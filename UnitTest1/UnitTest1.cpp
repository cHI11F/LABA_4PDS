#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>
#include "../PDS_LAB_4/PDS_LAB_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    
    std::string vectorToString(const std::vector<int>& vec) {
        std::ostringstream oss;
        for (const auto& val : vec) {
            oss << val << " ";
        }
        return oss.str();
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        
        TEST_METHOD(TestPermutations)
        {
            std::vector<int> expected1 = { 1, 2, 3 };
            std::vector<int> expected2 = { 1, 3, 2 };
            std::vector<int> expected3 = { 2, 1, 3 };
            std::vector<int> expected4 = { 2, 3, 1 };
            std::vector<int> expected5 = { 3, 1, 2 };
            std::vector<int> expected6 = { 3, 2, 1 };

            std::vector<std::vector<int>> expectedPermutations = { expected1, expected2, expected3, expected4, expected5, expected6 };

            int n = 3;
            std::vector<int> permutation;
            for (int i = 1; i <= n; ++i) {
                permutation.push_back(i);
            }

            int index = 0;
            do {
                Assert::AreEqual(vectorToString(permutation), vectorToString(expectedPermutations[index]));
                ++index;
            } while (std::next_permutation(permutation.begin(), permutation.end()));
        }

        
        TEST_METHOD(TestCombinations)
        {
            std::vector<int> elements = { 1, 2, 3, 4 };
            int r = 2;

            std::vector<std::string> expectedCombinations = {
                
            };

            std::vector<int> combination;
            std::ostringstream oss;
            generateCombinations(elements, combination, 0, r);

            
            int index = 0;
            generateCombinations(elements, combination, 0, r);
            for (int i = 0; i < expectedCombinations.size(); i++) {
                std::ostringstream oss;
                generateCombinations(elements, combination, 0, r);
                Assert::AreEqual(oss.str(), expectedCombinations[i]);
            }
        }

       
        TEST_METHOD(TestLogicalOperations)
        {
            bool p, q;
            p = true;
            q = false;

            bool expectedAnd = p && q;
            bool expectedOr = p || q;
            bool expectedXor = p ^ q;
            bool expectedImplication = !p || q;
            bool expectedEquivalence = (p && q) || (!p && !q);

            Assert::AreEqual(expectedAnd, false);
            Assert::AreEqual(expectedOr, true);
            Assert::AreEqual(expectedXor, true);
            Assert::AreEqual(expectedImplication, false);
            Assert::AreEqual(expectedEquivalence, false);
        }

        
        TEST_METHOD(TestBitwiseOperations)
        {
            std::bitset<8> b1("11111000");
            std::bitset<8> b2("10100110");

            std::bitset<8> expectedOr = b1 | b2;
            std::bitset<8> expectedAnd = b1 & b2;
            std::bitset<8> expectedXor = b1 ^ b2;

            Assert::AreEqual(expectedOr.to_ulong(), std::bitset<8>("11111110").to_ulong());
            Assert::AreEqual(expectedAnd.to_ulong(), std::bitset<8>("10100000").to_ulong());
            Assert::AreEqual(expectedXor.to_ulong(), std::bitset<8>("01011110").to_ulong());
        }
    };
}
