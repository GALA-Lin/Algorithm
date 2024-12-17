def qsort(arr,left,right):
    if len(arr) <= 1:
        return arr
    i,j=left,right
    pivot=arr[(left+right)//2]
    while i<=j:
            while arr[i]<pivot:
                    i+=1
            while arr[j]>pivot:
                    j-=1
            if i<=j:
                    arr[i],arr[j]=arr[j],arr[i]
                    i+=1
                    j-=1
    if left<j:
            qsort(arr,left,j)
    if i<right:
            qsort(arr,i,right)
    return arr
# Example usage:
arr=[5,2,8,3,1,6,9,4,7]
print(qsort(arr,0,len(arr)-1))