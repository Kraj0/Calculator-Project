#include "pch.h"
#include "gtest/gtest.h"
#include "conver.h"

//w teœcie zamieszczone zosta³y te same funkcje co w kalkulatorze

TEST(ConversionsTest_Dec2Bin, DecimalToBinary) {
    conver dec_bin;
    EXPECT_EQ(dec_bin.decimal2binary("000"), "0");
    EXPECT_EQ(dec_bin.decimal2binary("123"), "1111011"); 
    EXPECT_EQ(dec_bin.decimal2binary("255"), "11111111");
    EXPECT_EQ(dec_bin.decimal2binary("1565"), "11000011101"); 
}

TEST(ConversionsTest_Bin2Dec, BinaryToDecimal) {
    conver bin_dec;
    EXPECT_EQ(bin_dec.binary2decimal("000"), "0");
    EXPECT_EQ(bin_dec.binary2decimal("1111011"), "123");
    EXPECT_EQ(bin_dec.binary2decimal("11111111"), "255");
    EXPECT_EQ(bin_dec.binary2decimal("11000011101"), "1565");
}

TEST(ConversionsTest_Dec2Oct, DecimalToOctal) {
    conver dec_oct;
    EXPECT_EQ(dec_oct.decimal2oct("000"), "0");
    EXPECT_EQ(dec_oct.decimal2oct("123"), "173");
    EXPECT_EQ(dec_oct.decimal2oct("255"), "377");
    EXPECT_EQ(dec_oct.decimal2oct("1565"), "3035");
}

TEST(ConversionsTest_Oct2Dec, OctalToDecimal) {
    conver oct_dec;
    EXPECT_EQ(oct_dec.oct2decimal("000"), "0");
    EXPECT_EQ(oct_dec.oct2decimal("173"), "123");
    EXPECT_EQ(oct_dec.oct2decimal("377"), "255");
    EXPECT_EQ(oct_dec.oct2decimal("3035"), "1565");
}

TEST(ConversionsTest_Dec2Hex, DecimalToHexadecimal) {
    conver dec_hex;
    EXPECT_EQ(dec_hex.decimal2hex("000"), "0");
    EXPECT_EQ(dec_hex.decimal2hex("123"), "7B");
    EXPECT_EQ(dec_hex.decimal2hex("255"), "FF");
    EXPECT_EQ(dec_hex.decimal2hex("1565"), "61D");
}

TEST(ConversionsTest_Hex2Dec, HexadecimalToDecimal) {
    conver hex_dec;
    EXPECT_EQ(hex_dec.hex2decimal("000"), "0");
    EXPECT_EQ(hex_dec.hex2decimal("7B"), "123");
    EXPECT_EQ(hex_dec.hex2decimal("FF"), "255");
    EXPECT_EQ(hex_dec.hex2decimal("61D"), "1565");
}

/*TEST(ConversionsTest_error, error_test) {  //tutaj znajduje siê test specjalnie sprawdzaj¹cy 
// czyw razie podania z³ych wartoœci test wyka¿e b³¹d, (wszystko zadzia³a³o zgodnie z oczekiwaniami
// wiêc ta czêœæ zosta³a zakomentowana w celu lepszej przejrzystoœci testów)
    conver error_test;                       
    EXPECT_EQ(error_test.decimal2binary("0"), "1");
    EXPECT_EQ(error_test.decimal2binary("255"), "0010101");
    EXPECT_EQ(error_test.binary2decimal("1"), "0");
    EXPECT_EQ(error_test.binary2decimal("0010101"), "255");

    EXPECT_EQ(error_test.decimal2oct("0"), "1");
    EXPECT_EQ(error_test.decimal2oct("147"), "169");
    EXPECT_EQ(error_test.oct2decimal("1"), "0");
    EXPECT_EQ(error_test.oct2decimal("169"), "147");

    EXPECT_EQ(error_test.decimal2hex("0"), "1");
    EXPECT_EQ(error_test.decimal2hex("284"), "11D");
    EXPECT_EQ(error_test.hex2decimal("1"), "0");
    EXPECT_EQ(error_test.hex2decimal("11D"), "284");
}
*/

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}