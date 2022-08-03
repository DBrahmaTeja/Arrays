def permute(pos,arr,n,ans):
    if(pos>=n):
        ans.append(arr)
        return
    for i in range(pos,n):
        arr[pos],arr[i]=arr[i],arr[pos]
        permute(pos+1,arr,n,ans)
        arr[pos],arr[i]=arr[i],arr[pos]
 

def istriplet(a,b,c):
    lst2=[]
    arr=[a,b,c]
    permute(0,arr,3,lst2)
    for i in range(0,len(lst2)):
        if((lst2[i][2]**2==lst2[i][0]**2+lst2[i][1]**2) and (lst2[i][2]==lst2[i][0]**2-lst2[i][1])):
            return True
    print(lst2)
    return False

n=int(input())
l=[i for i in range(1,n+1)]
print(l)
#c2=a2+b2
#c=a2-b
set1=[]
for i in range(0,n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            if(istriplet(l[i],l[j],l[k])):
                set1.append([i+1,j+1,k+1])
print(set1)
print(len(set1))

