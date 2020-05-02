#include "build/temp/_test_e.c"
#include "src/CException.h"
#include "D:/LearnCeedling/vendor/ceedling/vendor/unity/src/unity.h"


volatile int TestingTheFallback;

volatile int TestingTheFallbackId;



void setUp(void)

{

    CExceptionFrames[0].pFrame = 

                                ((void *)0)

                                    ;

    TestingTheFallback = 0;

}



void tearDown(void)

{

}



void test_BasicTryDoesNothingIfNoThrow(void)

{

  int i = 0;

  unsigned int e = 0x5a;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    i += 1;

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityFail( (("Should Not Enter Catch If Not Thrown")), (UNITY_UINT)(28));

  }





  UnityAssertEqualNumber((UNITY_INT)((0x5a)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);





  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_BasicThrowAndCatch(void)

{

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    Throw(0xBE);

    UnityFail( (("Should Have Thrown An Error")), (UNITY_UINT)(45));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {



    UnityAssertEqualNumber((UNITY_INT)((0xBE)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

  }





  UnityAssertEqualNumber((UNITY_INT)((0xBE)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}



void test_BasicThrowAndCatch_WithMiniSyntax(void)

{

  unsigned int e;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

    Throw(0xEF);

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    UnityAssertEqualNumber((UNITY_INT)((0xEF)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0xEF)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

    e = 0;

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    UnityFail( (("I shouldn't be caught because there was no throw")), (UNITY_UINT)(72));



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

}



void test_VerifyVolatilesSurviveThrowAndCatch(void)

{

  volatile unsigned int VolVal = 0;

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    VolVal = 2;

    Throw(0xBF);

    UnityFail( (("Should Have Thrown An Error")), (UNITY_UINT)(86));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    VolVal += 2;

    UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

  }



  UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VolVal)), (

 ((void *)0)

 ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

}



void HappyExceptionThrower(unsigned int ID)

{

  if (ID != 0)

  {

    Throw(ID);

  }

}



void test_ThrowFromASubFunctionAndCatchInRootFunc(void)

{

  volatile unsigned int ID = 0;

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {



    HappyExceptionThrower(0xBA);

    UnityFail( (("Should Have Thrown An Exception")), (UNITY_UINT)(115));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    ID = e;

  }





  UnityAssertEqualNumber((UNITY_INT)((0xBA)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((UNITY_INT)((ID)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_INT);

}



void HappyExceptionRethrower(unsigned int ID)

{

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    Throw(ID);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    switch (e)

    {

    case 0xBD:

      Throw(0xBF);

      break;

    default:

      break;

    }

  }

}



void test_ThrowAndCatchFromASubFunctionAndRethrowToCatchInRootFunc(void)

{

  volatile unsigned int ID = 0;

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    HappyExceptionRethrower(0xBD);

    UnityFail( (("Should Have Rethrown Exception")), (UNITY_UINT)(157));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    ID = 1;

  }



  UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ID)), (

 ((void *)0)

 ), (UNITY_UINT)(165), UNITY_DISPLAY_STYLE_INT);

}



void test_ThrowAndCatchFromASubFunctionAndNoRethrowToCatchInRootFunc(void)

{

  unsigned int e = 3;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    HappyExceptionRethrower(0xBF);

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityFail( (("Should Not Have Re-thrown Error (it should have already been caught)")), (UNITY_UINT)(178));

  }





  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(182), UNITY_DISPLAY_STYLE_INT);

}



void test_ThrowAnErrorThenEnterATryBlockFromWithinCatch_VerifyThisDoesntCorruptExceptionId(void)

{

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    HappyExceptionThrower(0xBF);

    UnityFail( (("Should Have Thrown Exception")), (UNITY_UINT)(192));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(196), UNITY_DISPLAY_STYLE_INT);

    HappyExceptionRethrower(0x12);

    UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(198), UNITY_DISPLAY_STYLE_INT);

  }

  UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e)), (

 ((void *)0)

 ), (UNITY_UINT)(200), UNITY_DISPLAY_STYLE_INT);

}



void test_ThrowAnErrorThenEnterATryBlockFromWithinCatch_VerifyThatEachExceptionIdIndependent(void)

{

  unsigned int e1, e2;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    HappyExceptionThrower(0xBF);

    UnityFail( (("Should Have Thrown Exception")), (UNITY_UINT)(210));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e1 = CExceptionFrames[MY_ID].Exception; (void)e1; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e1)), (

   ((void *)0)

   ), (UNITY_UINT)(214), UNITY_DISPLAY_STYLE_INT);

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {

      HappyExceptionThrower(0x12);

    }

    else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e2 = CExceptionFrames[MY_ID].Exception; (void)e2; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    {

      UnityAssertEqualNumber((UNITY_INT)((0x12)), (UNITY_INT)((e2)), (

     ((void *)0)

     ), (UNITY_UINT)(221), UNITY_DISPLAY_STYLE_INT);

    }

    UnityAssertEqualNumber((UNITY_INT)((0x12)), (UNITY_INT)((e2)), (

   ((void *)0)

   ), (UNITY_UINT)(223), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e1)), (

   ((void *)0)

   ), (UNITY_UINT)(224), UNITY_DISPLAY_STYLE_INT);

  }

  UnityAssertEqualNumber((UNITY_INT)((0x12)), (UNITY_INT)((e2)), (

 ((void *)0)

 ), (UNITY_UINT)(226), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0xBF)), (UNITY_INT)((e1)), (

 ((void *)0)

 ), (UNITY_UINT)(227), UNITY_DISPLAY_STYLE_INT);

}



void test_CanHaveMultipleTryBlocksInASingleFunction(void)

{

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    HappyExceptionThrower(0x01);

    UnityFail( (("Should Have Thrown Exception")), (UNITY_UINT)(237));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityAssertEqualNumber((UNITY_INT)((0x01)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(241), UNITY_DISPLAY_STYLE_INT);

  }



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    HappyExceptionThrower(0xF0);

    UnityFail( (("Should Have Thrown Exception")), (UNITY_UINT)(247));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityAssertEqualNumber((UNITY_INT)((0xF0)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(251), UNITY_DISPLAY_STYLE_INT);

  }

}



void test_CanHaveNestedTryBlocksInASingleFunction_ThrowInside(void)

{

  int i = 0;

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {

      HappyExceptionThrower(0x01);

      i = 1;

      UnityFail( (("Should Have Rethrown Exception")), (UNITY_UINT)(266));

    }

    else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    {

      UnityAssertEqualNumber((UNITY_INT)((0x01)), (UNITY_INT)((e)), (

     ((void *)0)

     ), (UNITY_UINT)(270), UNITY_DISPLAY_STYLE_INT);

    }

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityFail( (("Should Have Been Caught By Inside Catch")), (UNITY_UINT)(275));

  }





  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

 ((void *)0)

 ), (UNITY_UINT)(279), UNITY_DISPLAY_STYLE_INT);

}



void test_CanHaveNestedTryBlocksInASingleFunction_ThrowOutside(void)

{

  int i = 0;

  unsigned int e;



  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {

      i = 2;

    }

    else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    {

      UnityFail( (("Should Not Be Caught Here")), (UNITY_UINT)(295));

    }

    HappyExceptionThrower(0x01);

    UnityFail( (("Should Have Rethrown Exception")), (UNITY_UINT)(298));

  }

  else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

  {

    UnityAssertEqualNumber((UNITY_INT)((0x01)), (UNITY_INT)((e)), (

   ((void *)0)

   ), (UNITY_UINT)(302), UNITY_DISPLAY_STYLE_INT);

  }





  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((i)), (

 ((void *)0)

 ), (UNITY_UINT)(306), UNITY_DISPLAY_STYLE_INT);

}



void test_AThrowWithoutATryCatchWillUseDefaultHandlerIfSpecified(void)

{



    TestingTheFallback = 1;



    Throw(0xBE);





    if (!(TestingTheFallback)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(317)));};

    UnityAssertEqualNumber((UNITY_INT)((0xBE)), (UNITY_INT)((TestingTheFallbackId)), (

   ((void *)0)

   ), (UNITY_UINT)(318), UNITY_DISPLAY_STYLE_INT);

}



void test_AThrowWithoutOutsideATryCatchWillUseDefaultHandlerEvenAfterTryCatch(void)

{

    unsigned int e;



    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {



    }

    else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    {



    }





    TestingTheFallback = 1;



    Throw(0xBE);





    if (!(TestingTheFallback)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(340)));};

    UnityAssertEqualNumber((UNITY_INT)((0xBE)), (UNITY_INT)((TestingTheFallbackId)), (

   ((void *)0)

   ), (UNITY_UINT)(341), UNITY_DISPLAY_STYLE_INT);

}



void test_AbilityToExitTryWithoutThrowingAnError(void)

{

    int i=0;

    unsigned int e;



    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {

        Throw((0x5A5A5A5A));

        i = 1;

        UnityFail( (("Should Have Exited Try Before This")), (UNITY_UINT)(353));

    }

    else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    {

        i = 2;

        UnityFail( (("Should Not Have Been Caught")), (UNITY_UINT)(358));

    }





    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(362), UNITY_DISPLAY_STYLE_INT);

}



void test_AbilityToExitTryWillOnlyExitOneLevel(void)

{

    int i=0;

    unsigned int e;

    unsigned int e2;



    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {

        { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; if (

       _setjmp((

       NewFrame

       ), __builtin_frame_address (0)) 

       == 0) { if (1)

        {

            Throw((0x5A5A5A5A));

            UnityFail( (("Should Have Exited Try Before This")), (UNITY_UINT)(376));

        }

        else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

        {

            UnityFail( (("Should Not Have Been Caught By Inside")), (UNITY_UINT)(380));

        }

        i = 1;

    }

    else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); ; } else { e2 = CExceptionFrames[MY_ID].Exception; (void)e2; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

    {

        UnityFail( (("Should Not Have Been Caught By Outside")), (UNITY_UINT)(386));

    }





    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(390), UNITY_DISPLAY_STYLE_INT);

}
