/*
Problem Link :- https://leetcode.com/problems/number-of-atoms/?envType=daily-question&envId=2024-07-14
*/

/*726. Number of Atoms

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 

Constraints:

1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.


*/

class Solution {
public:
    typedef unordered_map<string,int> MAP;

    string countOfAtoms(string formula) {
        int n = formula.length();

        stack<MAP> st;
        st.push(MAP());

        int i=0 ; 
        while(i<n){
            if(formula[i] == '('){
                st.push(MAP());
                i++;
            }
            else if(formula[i] == ')'){
                MAP currMap = st.top();
                st.pop();
                i++;

                string multiplier;
                while(i<formula.length() && isdigit(formula[i])){
                    multiplier += formula[i];
                    i++;
                }
                if(!multiplier.empty()){
                    int mult = stoi(multiplier);
                    for(auto& [atom,count] : currMap){
                        currMap[atom] = count*mult;
                    }
                }
                
                for(auto& [atom , count] : currMap){
                    st.top()[atom] += count;
                }
            }
            else{
                string currAtom;
                currAtom += formula[i];
                i++;

                while(i < n && islower(formula[i])){
                    currAtom += formula[i];
                    i++;
                }

                string currCount;
                while(i<n && isdigit(formula[i])){
                    currCount += formula[i];
                    i++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
        }

        map<string , int> sortedMap(begin(st.top()) , end(st.top()));

        string result;
        for(auto& [atom,count] : sortedMap){
            result += atom;
            if(count > 1){
                result += to_string(count);
            }
        }
        return result;
    }
};