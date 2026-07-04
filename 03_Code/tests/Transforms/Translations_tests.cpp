#include <gtest/gtest.h>
import std;
import vectors_basics;
import matrices_basics;
import transforms_translations;

TEST(TransformsTranslations, TranslationMatrixElements) {
    vectors::vector3 t(5.0, -2.0, 7.5);
    matrices::Matrix4x4 m = transforms::translationMatrix(t);

    EXPECT_FLOAT_EQ((m[0, 3]), 5.0);
    EXPECT_FLOAT_EQ((m[1, 3]), -2.0);
    EXPECT_FLOAT_EQ((m[2, 3]), 7.5);
    EXPECT_FLOAT_EQ((m[3, 3]), 1.0);
    EXPECT_FLOAT_EQ((m[0, 0]), 1.0);
}

TEST(TransformsTranslations, TranslateFunction) {
    vectors::vector3 t(3.0, 2.0, 1.0);
    vectors::vector3 p(10.0, 10.0, 10.0);

    vectors::vector3 res = transforms::translate(t, p);
    EXPECT_FLOAT_EQ(res.x, 13.0);
    EXPECT_FLOAT_EQ(res.y, 12.0);
    EXPECT_FLOAT_EQ(res.z, 11.0);
}
