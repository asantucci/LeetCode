class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Count how many times each value appears in the input using
        # an unordered map.
        counts = collections.defaultdict(int)
        for val in nums:
            counts[val] += 1
        # Sort the output of a lambda expression which says:
        # "frequency, value for each value"
        freqs = sorted([(counts[key], key) for key in counts], reverse = True)
        return [val for freq, val in freqs[:k]]

    # Realize that the above implementation is O(n) + O(n*log n)
    # Can we do better? Sure, just go ahead and make
    # the a freqs container from the get go that is length 1 + size of input.
    # We trade time with space complexity, where now we incur an O(n) storage.
    # The reason we do this is because the max # times an element can appear
    # is length(size of input). And, we're going to use this container
    # to associate a count with each input value.
    # Our runtime will reduce to O(n).
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # A value could appear exactly length(input), but we're counting from
        # 1, so make the listing of frequencies 1 + length(nums).
        freqs = [[] for i in range(len(nums) + 1)]
        counts = collections.defaultdict(int)
        for val in nums:
            counts[val] += 1
        # OK, now, for each value in input, we're going to describe its frequency
        # inside of an O(n) container. Note that elements can appear the 'same'
        # number of times so use a list and append (e.g. it could be that our input
        # has only 2 values, each of which appear n/2 times. Then we'd want to
        # store both these values at the n/2th position in the freqs listing).
        for val, count in counts.items():
            freqs[count].append(val)
        # Now just iterate over this O(n) container 'from the backwards end', where
        # the counts (or frequencies) are highest, until we populate K words.
        res = []
        for i in range(len(freqs) - 1, 0, -1):
            for val in freqs[i]:
                res.append(val)
                if len(res) == k:
                    return res
