#include "build/temp/_test_ras.c"
#include "src/ras.h"
#include "D:/LearnCeedling/vendor/ceedling/vendor/unity/src/unity.h"


char buffer[100];

void setUp(void)

{

    memset(buffer, 0, 100);

}

void tearDown(void)

{

}

void test_ras_StringWithSpace_WithoutSpace(void)

{

    strcpy(buffer, "this is a test");

    char *actual = ras(buffer, " ");

    char *expected = "thisisatest";



    UnityAssertEqualString((const char*)((expected)), (const char*)((actual)), (

   ((void *)0)

   ), (UNITY_UINT)(19));

}

void test_ras_StringWithNumber_WithoutNumber(void)

{

    strcpy(buffer, "1this123is456a7890tes2t3");

    char *actual = ras(buffer, "1234567890");

    char *expected = "thisisatest";



    UnityAssertEqualString((const char*)((expected)), (const char*)((actual)), (

   ((void *)0)

   ), (UNITY_UINT)(27));

}



void test_ras_out_of_range(void)

{

    memset(buffer, 'X', 100);

    strcpy(&buffer[5], " 1a 2b 3c 4d ");

    int len = strlen(&buffer[5]);

    char *actual = ras(&buffer[5], " ");

    char *expected = "1a2b3c4d";



    UnityAssertEqualString((const char*)((expected)), (const char*)((actual)), (

   ((void *)0)

   ), (UNITY_UINT)(38));

    buffer[5] = 0;

    UnityAssertEqualString((const char*)(("XXXXX")), (const char*)((buffer)), (

   ((void *)0)

   ), (UNITY_UINT)(40));

    UnityAssertEqualIntArray(( const void*)(('X')), ( const void*)((buffer[5 + len + 1])), (UNITY_UINT32)(((100 - 5 - len - 1))), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_CHAR, UNITY_ARRAY_TO_ARRAY);

}
