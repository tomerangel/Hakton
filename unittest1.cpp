#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\USER\Desktop\Project1\Project1\main.cpp"
#include "C:\Users\USER\Desktop\Project1\Project1\Card.cpp"
#include "C:\Users\USER\Desktop\Project1\Project1\Deck.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Card d(52,2);
			Deck c();
			Assert::AreEqual(d.getValue,d.setCard);
			Assert::AreNotSame(d.getValue, d.setCard);

			Assert::AreEqual(d.display, d.setCard);
			Assert::AreNotSame(d.setCard, d.display);
			Assert::AreEqual(d.getValue, d.setCard);
			Assert::IsFalse(d.display, d.setCard);
			//Assert::AreEqual(d.getValue, d.setCard);
			//Assert::IsTrue(d.getValue, d.setCard);

		}

	};
}