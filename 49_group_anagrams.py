from collections import defaultdict

# Solution requires sorting each input string
# O(n * m log m) where n is number of input strings
# and m is the length of the largest string.
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_chars = defaultdict(int)
        t_chars = defaultdict(int)
        for char in s:
            s_chars[char] += 1
        for char in t:
            t_chars[char] += 1
        for key in s_chars:
            if s_chars[key] != t_chars[key]:
                return False
        for key in t_chars:
            if t_chars[key] != s_chars[key]:
                return False
        return True
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        ans = {}
        for word in strs:
            sorted_word = "".join(sorted(word))
            if sorted_word in ans:
                ans[sorted_word].append(word)
            else:
                ans[sorted_word] = [word]
        return [ans[key] for key in ans]

# Here's another "faster" solution, O(n*m)
# The core idea is that we simply count the number of characters
# of each type (of character) and then use a count-pattern
# (of length the size of the alphabet) as key in a dictionary
# that creates, for each key, a listing of strings with equal
# count-pattern, i.e. a listing of anagrams.
from collections import defaultdict

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        ans = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            ans[tuple(count)].append(s)
        return ans.values()
