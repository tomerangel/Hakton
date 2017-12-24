import math
from functools import reduce
"""
def make_matrix(n,m,arr):
    def dispatch(message):
        if message=='n':
            return n
        if message=='m':
            return m
        if message=='matrix':
            return arr
    return dispatch
def n(obj):
    print (obj('n'))
def m(obj):
    print (obj('m'))
def matrix(obj):
    print (obj('matrix'))
def PrintMatrix(obj):
    row=obj('n')
    col=obj('m')
    arr=obj('matrix')
    k=0
    for i in range (row):
        for j in range (col):
            print(arr[k],end=" ")
            k+=1
        print()
def AddMatrix(obj1,obj2):
    row1=obj1('n')
    col1=obj1('m')
    arr1=obj1('matrix')
    arr2=obj2('matrix')
    new_arr=[0]*row1*col1
    k=0
    for i in range(row1):
        for j in range (col1):
            new_arr[k]=arr1[k]+arr2[k]
            k+=1
    New=make_matrix(row1,col1,new_arr)
    return New
def InvertMatrix(obj):
    row=obj('n')
    col=obj('m')
    arr=obj('matrix')
    k=0
    temp=arr[k]
   
    t=0
    new_arr=[0]*row*col
    for i in range (0,col):
        new_arr[k]=arr[i]
        k+=2
    k=1
    for j in range (col,col+row+1,1):
        new_arr[k]=arr[j]
        k+=2
            
    New=make_matrix(col,row,new_arr)
    return New
def MulMatrix(obj1,obj2):
    row1=obj1('n')
    col1=obj1('m')
    arr1=obj1('matrix')
    row2=obj2('n')
    col2=obj2('m')
    arr2=obj2('matrix')
    new_arr=[0]*row1*col2
    k=0
    for i in range (0,(col2+row2+1)//2):
        for j in range (0,(row1+col1),2):
            new_arr[k]+=(arr1[i]*arr2[j])
            i+=1
        k+=1
        i=0
    New=make_matrix(col1-1,row2-1,new_arr)
    return New
    
m1=make_matrix(2,3,[1,2,3,4,5,6])
print(m1)
n(m1)
m(m1)
matrix(m1)
print()
PrintMatrix(m1)
print()
m2=make_matrix(2,3,[3,4,5,6,7,8])
PrintMatrix(m2)
print()
PrintMatrix(AddMatrix(m1,m2))
print()
PrintMatrix(InvertMatrix(m1))
print()
PrintMatrix(MulMatrix(m1,InvertMatrix(AddMatrix(m1,m2))))

"""

def data_preprocessing(data,min_val,max_val):
    new_data=data.split(',')
    new_data=list(filter(lambda x:'x' if x=='' else int(x)>=min_val and int(x)<=max_val,new_data))
    return list(map(lambda x:((int(new_data[x-1])+int(new_data[x+1]))//2) if (new_data[x]=='') else int(new_data[x]),range(len(new_data))))
def data_preprocessing_histogram(data,min_val,max_val):
    data2=data_preprocessing(data,min_val,max_val)
    temp=list(set(map(lambda x:(x,data2.count(x)),data2)))
    return temp
def data_preprocessing_range(data,min_val,max_val):
    data1=data_preprocessing(data,min_val,max_val)
    data2=(min(data1),reduce(lambda x,y:x+y , data1)/len(data1),max(data1))
    return (data2)#(lambda x,y:x+y reduce(f,data2)
    
    


data = "1,1,,100,3, 5,5,5,,1,2,3"
min_val,max_val = 0,10
print(data_preprocessing(data,min_val,max_val))
print(data_preprocessing_histogram(data,min_val,max_val))
print(data_preprocessing_range(data,min_val,max_val))

"""
def make_mydate(day=1,monthe=1,year=2017):
    def dispatch(message):
        if message=='view':
            def view(kindOfPrint='dmy'):
                if kindOfPrint=='mdy':
                    print("%02d/%02d/%02d"%(monthe,day,year))
                elif kindOfPrint=='dmy':
                    print("%02d/%02d/%02d"%(day,monthe,year))
                elif kindOfPrint=='ymd':
                    print("%02d/%02d/%02d"%(year,monthe,day))
                else:
                    print("format error")
            return view
        if message=='set':
            def set(change,val):
                nonlocal day
                nonlocal monthe
                nonlocal year
                if change =='day':
                    day=val
                if change =='monthe':
                    monthe=val
                if change =='year':
                    year=val
            return set
        if message=='get':
            def get(getDate):
                if getDate=='day':
                    return day
                if getDate=='monthe':
                    return monthe
                if getDate=='year':
                    return year
            return get
        if message=='next date':
            nonlocal day
            nonlocal monthe
            nonlocal year
            if monthe==4 or monthe==6 or monthe==9 or monthe==11:
                if day<30:
                    day+=1
                elif day==30:
                    day=1
                    monthe+=1
            elif monthe==2:
                if day<28:
                    day+=1
                elif day==28:
                    day=1
                    monthe+=1
            elif monthe==12:
                if day<31:
                    day+=1
                elif day==31:
                    day=1
                    monthe=1
                    year+=1
            elif monthe==1 or monthe==3 or monthe==5 or monthe==7 or monthe==8 or monthe==10:
                if day<31:
                    day+=1
                elif day==31:
                    day=1
                    monthe+=1
        if message=='days between dates':
            def days_between_dates(date2):
                year2=date2('get')('year')
                monthe2=date2('get')('monthe')
                day2=date2('get')('day')
                if year==year2 and monthe==monthe2:
                    sum1=abs(day2-day)
                    print(sum1)
                else:
                    print("years and monthes are not the same!")
            return days_between_dates
    return dispatch

d1=make_mydate()
d1
print(d1)
d1('view')('mdy')
d1('set')('day',31)
d1('set')('monthe',12)
d1('view')('ydm')
d1('view')('ymd')
d1('next date')
d1('view')('mdy')
d2=make_mydate(23,1,2018)
d2('view')()
d1('days between dates')(d2)
"""
"""
def make_sequence(lst):
    i=0
    j=len(lst)-1
    def all_filter(func=lambda x:x):
        return tuple(filter(func,lst))
    def return_filter(func=lambda x:x):
        return make_sequence(tuple(filter(func,lst)))
    def mynext():
        nonlocal i
        temp=len(lst)
        print(lst[i])
        
        i+=1
        if(i==temp):
            i=0
     
    def reverse():
        nonlocal j
        print(lst[j])
        if(j==0):
            j=len(lst)
        j-=1
    def extend(lst2):
        nonlocal lst
        lst=list(lst)
        temp2=list(lst2)
        lst.extend(temp2)
        lst = tuple(lst)
        return lst
        
    def clear():
        nonlocal lst
        lst=list(lst)
        lst2=lst
        del lst[:]
        print(lst2)
    return{'all_filter':all_filter,'next':mynext,'return_filter':return_filter,'reverse':reverse,'extend':extend,'clear':clear}


s1=make_sequence((1,2,3,4,5))
s1['all_filter'](lambda x: x%2==0)
p1=s1['return_filter'](lambda x: x<4)
p1['next']()
for _ in range(5):
    p1['next']()	
for _ in range(3):
    p1['reverse']()
s1['extend'](s1['all_filter'](lambda x: x%2!=0))
print(s1['all_filter'](lambda x: x>2))
print(s1['all_filter']())
make_sequence(s1['reverse']()))['all_filter'](lambda x: x<4)
s1['clear']()
"""
"""

def make_rlist(first, rest):
    return (first, rest)
def len_rlist(s):
    length = 0
    while s != empty_rlist:
        s,length = rest(s), length + 1
    return length
def getitem_rlist(s, i):
    while i > 0:
        s, i = rest(s), i - 1
    return first(s)
def first(s):
    return s[0]
def rest(s):
    return s[1]

def make_mutable_rlist():
    empty_rlist = None
    contents = empty_rlist
    def length():
        return len_rlist(contents)
    def get_item(ind):
        return getitem_rlist(contents, ind)
    def push_first(value):
	nonlocal contents
	contents = make_rlist(value, contents)
    def pop_first():
	nonlocal contents
	f = first(contents)
	contents = rest(contents)
	return f
    def str1():
        i=0
        str1[i]=length
        while(get_item[i]!=None):
            str[i]=get_item
        return str(list(str1)
    return {'length':length, 'get_item':get_item, 'push_first':push_first, 
		             'pop_first': pop_first, 'str':str}
my_list = make_mutable_rlist()
for x in range(4)
    my_list['push_first'](x)
my_list['str']()

"""

