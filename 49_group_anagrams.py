from collections import defaultdict

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
