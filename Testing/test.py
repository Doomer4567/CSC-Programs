def sum13(nums):
  num = 0
  i = -1
  for x in nums:
    if x != 13 and nums[i] != 13:
      num += x
    i+=1  
  print(num)


sum13([13, 1, 2, 13, 2, 1, 13])