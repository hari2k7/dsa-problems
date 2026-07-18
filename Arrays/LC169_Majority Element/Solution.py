class Solution:
    def majorityElement(self, nums):
        element = 0
        count = 0

        for num in nums:
            if count == 0:
                element = num
                count = 1
            elif num == element:
                count += 1
            else:
                count -= 1

        cnt = 0
        for num in nums:
            if num == element:
                cnt += 1

        if cnt > len(nums) // 2:
            return element
        return -1


if __name__ == "__main__":
    sol = Solution()

    nums1 = [3, 2, 3]

    print("Array:", nums1)
    print("Majority Element:", sol.majorityElement(nums1))