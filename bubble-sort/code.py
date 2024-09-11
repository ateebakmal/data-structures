# Book Implementation:
def bubble_sort(list ):
   sorted_until_index = len(list) - 1
   sorted = False

   while not sorted:
      sorted = True

      for i in range(sorted_until_index):

         if list[i] > list[i + 1]:
            sorted = False
            #swap
            list[i] , list[i + 1] = list[i + 1] , list[i]

      #Last value is sorted
      sorted_until_index -= 1

#Implementation 2
def bubble_sort_2(list):
   for i in range(0 , len(list) - 1):
      flag = 0

      for j in range(0 , len(list) - 1 - i):

         if list[j] > list[j + 1]:
            #swap
            list[j] , list[j + 1] = list[j + 1] , list[j]
            flag += 1
         
      if flag == 0:
         break

list = [8,5,3,2,7]
bubble_sort_2(list)
print(list)