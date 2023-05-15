class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        nums=0;
        for i in num:
            nums=nums*10+i
        nums=nums+k
        l=[]
        while(nums!=0):
            l.append(nums%10)
            nums=nums//10
        
        l.reverse()
        return l