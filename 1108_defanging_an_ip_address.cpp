/* Given a valid (IPv4) IP address, return a defanged 
   version of that IP address.
   A defanged IP address replaces every period "." with "[.]".
*/
class Solution {
public:
    string defangIPaddr(string address) {
        int idx = address.find('.');
        while (idx != string::npos) {
            // The tricky part is to realize that insertion
            // happens exactly AT the index specified.
            address.insert(idx, 1, '[');
            // Further, this means that after insertion,
            // the '.' character is found at position
            // idx+1, so to insert a ']' after the period
            // we need to insert at posn idx + 2.
            address.insert(idx + 2, 1, ']');
            // By similar reasoning, our '.' character
            // got shifter into position idx+1, so start
            // our next search at position idx+2.
            idx = address.find('.', idx+2);
        }
        return address;
    }
};
