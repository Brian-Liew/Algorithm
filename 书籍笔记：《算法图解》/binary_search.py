# def binary_search(list,item):
# 	low = 0;
# 	high = len(list)-1
# 	while low <= high :
# 		mid = int((low+high)/2)
# 		guess =list[mid]
# 		if guess == item:
# 			return mid
# 		if guess < item:
# 			low = mid+1
# 		else:
# 			high=mid-1
# 	return None
# my_list =[1,3,5,7,9]
# print (binary_search(my_list,5))
# print (binary_search(my_list,-1))

N = input()
N=int (N)
max_len = 0.0
min_len = 0.0
num=[0]*N
for i in range(N):
	num[i]=int (input())
	if num[i]>max_len:
		max_len=num[i]
M = input()
M=int (M)
def check(length):
	ans = 0
	for i in range(N):
		ans += (int)(num[i]/length)
	return ans
while max_len-min_len>=0.00001:
	mid = (max_len+min_len)/2
	if(M>check(mid)):
		max_len=mid
	else:
		min_len=mid
print(mid)