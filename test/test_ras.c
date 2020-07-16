#include <string.h>
#include "unity.h"
#include "ras.h"
#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE];
void setUp(void)
{
    memset(buffer, 0, BUFFER_SIZE);
}
void tearDown(void)
{
}
void test_ras_StringWithSpace_WithoutSpace(void)
{
    strcpy(buffer, "this is a test");
    char *actual = ras(buffer, " ");
    char *expected = "thisisatest";

    TEST_ASSERT_EQUAL_STRING(expected, actual);
}
void test_ras_StringWithNumber_WithoutNumber(void)
{
    strcpy(buffer, "1this123is456a7890tes2t3");
    char *actual = ras(buffer, "1234567890");
    char *expected = "thisisatest";

    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_ras_out_of_range(void)
{
    memset(buffer, 'X', BUFFER_SIZE);
    strcpy(&buffer[5], " 1a 2b 3c 4d ");
    int len = strlen(&buffer[5]);
    char *actual = ras(&buffer[5], " ");
    char *expected = "1a2b3c4d";

    TEST_ASSERT_EQUAL_STRING(expected, actual);
    buffer[5] = 0;
    TEST_ASSERT_EQUAL_STRING("XXXXX", buffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY('X', buffer[5 + len + 1], (BUFFER_SIZE - 5 - len - 1));
}
