#include <gtest/gtest.h>

#include <cmath>

#include "Model.h"
const double eps = 1e-6;

TEST(operators, plus) {
  sfleta_::Model model;

  std::string inputStr = "2.0+3.32";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  double result = 2.0 + 3.32;
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "12+0.0";
  result = 12 + 0.0;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-12+2.34";
  result = -12 + 2.34;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "100+-234.0";
  result = 100 + -234.0;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "9+(8+6)+1+(3+9)";
  result = 9 + (8 + 6) + 1 + (3 + 9);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "21892683+(+60607476)";
  result = 21892683 + (+60607476);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "794+(101+110)+387";
  result = 794 + (101 + 110) + 387;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(operators, test_minus) {
  sfleta_::Model model;

  std::string inputStr = "416-434";
  double result = 416 - 434;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "107-(928-166-438)";
  result = 107 - (928 - 166 - 438);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(399-985)-63-352";
  result = (399 - 985) - 63 - 352;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "107-(928-166-438)";
  result = 107 - (928 - 166 - 438);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "107-(928-166-438)";
  result = 107 - (928 - 166 - 438);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(399-985)-63-352";
  result = (399 - 985) - 63 - 352;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "317-141-(118-695)";
  result = 317 - 141 - (118 - 695);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(3879294-5309583)-(3744311-2467480-4787696)-3324295";
  result = (3879294 - 5309583) - (3744311 - 2467480 - 4787696) - 3324295;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(operators, test_mult) {
  sfleta_::Model model;

  std::string inputStr = "65991.0*(0.5312*5213.0)*-(0.9450*897643.0)";
  double result = 65991.0 * (0.5312 * 5213.0) * -(0.9450 * 897643.0);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(-0.38227*7856.815-0.0)*(7759.3*-51507.96)";
  result = (-0.38227 * 7856.815 - 0.0) * (7759.3 * -51507.96);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "6916.08*-(5855.31*75.6934)*-(-3272.10*4382.36)";
  result = 6916.08 * -(5855.31 * 75.6934) * -(-3272.10 * 4382.36);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(-816.484*5.2422)*5106.881*(4849.3*401.9244)";
  result = (-816.484 * 5.2422) * 5106.881 * (4849.3 * 401.9244);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(91.226*-51.9)*(7.797*85.481)";
  result = (91.226 * -51.9) * (7.797 * 85.481);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-25.9655*-(-626.93*508.657)*(85.108*400.162)";
  result = -25.9655 * -(-626.93 * 508.657) * (85.108 * 400.162);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-(-356.081*4598.63)*803.928*(70.592*0.1569)*-36.1566";
  result = -(-356.081 * 4598.63) * 803.928 * (70.592 * 0.1569) * -36.1566;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(operators, test_div) {
  sfleta_::Model model;

  std::string inputStr = "(432/9.57/321)/(76.4/78.0)/-35.8";
  double result = (432 / 9.57 / 321) / (76.4 / 78.0) / -35.8;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "43.1/(495.5/711.0)/28.7";
  result = 43.1 / (495.5 / 711.0) / 28.7;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(0.5757/23.3/704.1/-31.27)";
  result = (0.5757 / 23.3 / 704.1 / -31.27);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(2451.0/43.94/-1.759)/62.72";
  result = (2451.0 / 43.94 / -1.759) / 62.72;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(1.375/930.0)/223.3/80.41";
  result = (1.375 / 930.0) / 223.3 / 80.41;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "4.091/(23.04/1.075/42.8)";
  result = 4.091 / (23.04 / 1.075 / 42.8);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(7068.0/33.59/9.13-4)/43.5";
  result = (7068.0 / 33.59 / 9.13 - 4) / 43.5;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "97.66/(705.2/2619.0)/59.59";
  result = 97.66 / (705.2 / 2619.0) / 59.59;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(operators, test_pow) {
  sfleta_::Model model;

  std::string inputStr = "8^(3^4)";
  double result = pow(8, pow(3, 4));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(2^9)^1";
  result = pow(pow(2, 9), 1);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "2^2^3";
  result = (pow(2, pow(2, 3)));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "5^(3^3)";
  result = (pow(5, pow(3, 3)));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(4^10)^3";
  result = pow(pow(4, 10), 3);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(8^2)^8";
  result = pow(pow(8, 2), 8);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(4^10)^3";
  result = pow(pow(4, 10), 3);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(operators, test_mod) {
  sfleta_::Model model;

  std::string inputStr = "(45.34mod55.23)mod79.4";
  double result = fmod(fmod(45.34, 55.23), 79.4);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "357.34mod(952.34mod712.12)";
  result = fmod(357.34, fmod(952.34, 712.12));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "15.234mod(0.52mod0.034)";
  result = fmod(15.234, fmod(0.52, 0.034));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "499.23mod(1.8mod0.27)";
  result = fmod(499.23, fmod(1.8, 0.27));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "22modx";
  result = fmod(22, 20);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetX(20);
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "22mod-x";
  double x = 20;
  result = fmod(22, -x);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetX(x);
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "22mod-x";
  x = -20;
  result = fmod(22, x);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetX(x);
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(operators, test_mix) {
  sfleta_::Model model;

  std::string inputStr = "(72*533+-615)";
  double result = (72 * 533 + -615);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "826-(738-+243)";
  result = 826 - (738 - +243);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "17mod863*-173";
  result = fmod(17, 863) * -173;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "40.34*(-0.424/-252)";
  result = 40.34 * (-0.424 / -252);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "(944mod918)/227";
  result = (fmod(944, 918)) / 227;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);
}

TEST(functions, test_etc) {
  sfleta_::Model model;

  std::string inputStr = "34.4+34/3";
  model.SetInputString(inputStr);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "34..4+5";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "34./.4+5";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "--34+5";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "*34+5";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "34*-5";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "34-*5";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "-(2*2)";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "mod";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "2mod";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "2mod/3";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "2mod(3)";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = ")2+2";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "2(+)3";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "2+(*3)";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "*mod20";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));
}

TEST(sci_notation, test_func) {
  sfleta_::Model model;

  std::string inputStr = "acos(0.1)*sin(1)";
  double result = acos(0.1) * sin(1);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "cos(-1.34)+tan(+2.0)";
  result = cos(-1.34) + tan(+2);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-(asin(+0.3465346)/2)";
  result = -(asin(+0.3465346) / 2);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "+atan(1.302+0.5)-1.2";
  result = +atan(1.302 + 0.5) - 1.2;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "123modsqrt(100)";
  result = fmod(123, sqrt(100));
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "log(+123.345)";
  result = log10(+123.345);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  double x = 5.5;
  inputStr = "ln(x)";
  result = log(x);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  model.SetX(x);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-sin(1)";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "sin1";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "sims(3)+cs(1.6)";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "2+3/sin()";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "sin)";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));
}

TEST(sci_notation, test_sci_notation) {
  sfleta_::Model model;

  std::string inputStr = "10e2";
  double result = 10e2;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "10e-2";
  result = 10e-2;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "10e+2";
  result = 10e+2;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "10e8+10e-9";
  result = 10e8 + 10e-9;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "10.434e8+10.3656e-9-10";
  result = 10.434e8 + 10.3656e-9 - 10;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-3.24e-3+2.343e+2";
  result = -3.24e-3 + 2.343e+2;
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "-3.24+33mod2.343e-2";
  result = -3.24 + fmod(33, 2.343e-2);
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
  model.SetInputString(inputStr);
  EXPECT_NEAR(model.GetResult(), result, eps);

  inputStr = "10e";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "10ee3";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "e";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "10e-";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));

  inputStr = "10e-1.23";
  ASSERT_FALSE(model.IsNormalInputString(inputStr));
}

TEST(x, test_x) {
  sfleta_::Model model;
  std::string inputStr = "-x";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "+x";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "+x-xmod3";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "-x+-x";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "sin(x+3)--x";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));

  inputStr = "(2e-2)mod(sin(x))";
  ASSERT_TRUE(model.IsNormalInputString(inputStr));
}

TEST(credit, test_credit) {
  sfleta_::Model model;

  double result = model.CreditCalc(100000, 12, 15, 1);
  EXPECT_NEAR(9025.83, result, 1e-2);

  result = model.CreditCalc(100000, 12, 15, 2);
  EXPECT_NEAR(9583.33, result, 1e-2);

  result = model.CreditCalc(300000, 42, 5, 1);
  EXPECT_NEAR(7800.91, result, 1e-2);

  result = model.CreditCalc(300000, 42, 5, 2);
  EXPECT_NEAR(8392.86, result, 1e-2);

  result = model.CreditCalc(1, 1, 1, 1);
  EXPECT_NEAR(1.00, result, 1e-2);

  result = model.CreditCalc(10000000000, 600, 999.99, 1);
  EXPECT_NEAR(8.33325e+09, result, 1e-2);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}