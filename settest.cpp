#include "stdafx.h"
#include "CppUnitTest.h"
#include "DefaultKeyboardAPI.h"
#include "DefaultKeyboardAPI.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(SetTest)
	{
        DefaultKeyboardAPI key;
    public:
		
		TEST_METHOD(SingeKeypresses)
		{
            Assert::IsTrue(1 == key.set(KKC1, true));
            AssertKeysPressed(KKC1);

            Assert::IsTrue(1 == key.set(KKC1, false));
            AssertKeysPressed();
        }

        TEST_METHOD(MultipleKeypresses)
        {
            Assert::IsTrue(1 == key.set(KKC1, true));
            Assert::IsTrue(1 == key.set(KKC2, true));
            Assert::IsTrue(1 == key.set(KKC3, true));
            AssertKeysPressed(KKC1,KKC2,KKC3);

            Assert::IsTrue(1 == key.set(KKC1, false));
            AssertKeysPressed(KKC2, KKC3);

            Assert::IsTrue(1 == key.set(KKC3, false));
            AssertKeysPressed(KKC2);
        }

        TEST_METHOD(Full)
        {
            Assert::IsTrue(1 == key.set(KKC1, true));
            Assert::IsTrue(1 == key.set(KKC2, true));
            Assert::IsTrue(1 == key.set(KKC3, true));
            Assert::IsTrue(1 == key.set(KKC4, true));
            Assert::IsTrue(1 == key.set(KKC5, true));
            Assert::IsTrue(1 == key.set(KKC6, true));
            AssertKeysPressed(KKC1, KKC2, KKC3, KKC4, KKC5, KKC6);
            Assert::IsTrue(0 == key.set(KKC7, true));
            AssertKeysPressed(KKC1, KKC2, KKC3, KKC4, KKC5, KKC6);

            Assert::IsTrue(1 == key.set(KKC6, false));
            AssertKeysPressed(KKC1, KKC2, KKC3, KKC4, KKC5);

            Assert::IsTrue(1 == key.set(KKC6, true));
            AssertKeysPressed(KKC1, KKC2, KKC3, KKC4, KKC5, KKC6);

            Assert::IsTrue(1 == key.set(KKC1, false));
            AssertKeysPressed(KKC2, KKC3, KKC4, KKC5, KKC6);
        }

        TEST_METHOD(Dups)
        {
            Assert::IsTrue(1 == key.set(KKC1, true));
            Assert::IsTrue(0 == key.set(KKC1, true));
            AssertKeysPressed(KKC1);

            Assert::IsTrue(1 == key.set(KKC1, false));
            Assert::IsTrue(0 == key.set(KKC2, false));
            Assert::IsTrue(0 == key.set(KKC1, false));
            AssertKeysPressed();
        }

        void AssertKeysPressed(
            KeyboardKeycode k1 = KEY_RESERVED,
            KeyboardKeycode k2 = KEY_RESERVED,
            KeyboardKeycode k3 = KEY_RESERVED,
            KeyboardKeycode k4 = KEY_RESERVED,
            KeyboardKeycode k5 = KEY_RESERVED,
            KeyboardKeycode k6 = KEY_RESERVED)
        {
            Assert::AreEqual((int)k1, (int)key._keyReport.keycodes[0]);
            Assert::AreEqual((int)k2, (int)key._keyReport.keycodes[1]);
            Assert::AreEqual((int)k3, (int)key._keyReport.keycodes[2]);
            Assert::AreEqual((int)k4, (int)key._keyReport.keycodes[3]);
            Assert::AreEqual((int)k5, (int)key._keyReport.keycodes[4]);
            Assert::AreEqual((int)k6, (int)key._keyReport.keycodes[5]);
        }
    };
}