#include <catch/catch.hpp>

#include <biscuit/assembler.hpp>

using namespace biscuit;

TEST_CASE("C.ADDI4SPN", "[rvc]") {
    uint32_t value = 0;
    Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.C_ADDI4SPN(x15, 0xFF);
    REQUIRE(value == 0x1FFC);

    as.RewindBuffer();

    as.C_ADDI4SPN(x8, 0xFF);
    REQUIRE(value == 0x1FE0);
}

TEST_CASE("C.FLD", "[rvc]") {
    uint32_t value = 0;
    Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.C_FLD(f15, 8, x15);
    REQUIRE(value == 0x279C);

    as.RewindBuffer();

    as.C_FLD(f15, 24, x15);
    REQUIRE(value == 0x2F9C);
}

TEST_CASE("C.UNDEF", "[rvc]") {
    uint32_t value = 0;
    Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.C_UNDEF();
    REQUIRE(value == 0);
}