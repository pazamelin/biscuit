#include <catch/catch.hpp>

#include <biscuit/assembler.hpp>

using namespace biscuit;

TEST_CASE("FMADD.S", "[rv32f]") {
    uint32_t value = 0;
    Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.FMADD_S(f15, f31, f7, f26, Assembler::RMode::RNE);
    REQUIRE(value == 0xD07F87C3);

    as.RewindBuffer();

    as.FMADD_S(f15, f31, f7, f26, Assembler::RMode::RMM);
    REQUIRE(value == 0xD07FC7C3);

    as.RewindBuffer();

    as.FMADD_S(f15, f31, f7, f26, Assembler::RMode::DYN);
    REQUIRE(value == 0xD07FF7C3);
}

TEST_CASE("FLW", "[rv32f]") {
    uint32_t value = 0;
    Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.FLW(f15, 1024, x31);
    REQUIRE(value == 0x400FA787);

    as.RewindBuffer();

    as.FLW(f15, 2048, x31);
    REQUIRE(value == 0x800FA787);

    as.RewindBuffer();

    as.FLW(f15, 4095, x31);
    REQUIRE(value == 0xFFFFA787);
}

TEST_CASE("FSW", "[rv32f]") {
    uint32_t value = 0;
    Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.FSW(f31, 1024, x15);
    REQUIRE(value == 0x41F7A027);

    as.RewindBuffer();

    as.FSW(f31, 2048, x15);
    REQUIRE(value == 0x81F7A027);

    as.RewindBuffer();

    as.FSW(f31, 4095, x15);
    REQUIRE(value == 0xFFF7AFA7);
}
