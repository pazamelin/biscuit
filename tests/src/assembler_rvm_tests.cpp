#include <catch/catch.hpp>

#include <biscuit/assembler.hpp>

TEST_CASE("MUL", "[rv64m]") {
    uint32_t value = 0;
    biscuit::Assembler as(reinterpret_cast<uint8_t*>(&value), sizeof(value));

    as.MUL(biscuit::x31, biscuit::x15, biscuit::x20);
    REQUIRE(value == 0x03478FB3);

    as.RewindBuffer();

    as.MUL(biscuit::x31, biscuit::x20, biscuit::x15);
    REQUIRE(value == 0x02FA0FB3);

    as.RewindBuffer();

    as.MUL(biscuit::x20, biscuit::x31, biscuit::x15);
    REQUIRE(value == 0x02FF8A33);
}
