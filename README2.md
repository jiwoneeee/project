linked list 랑 quick sort 합쳣 사용하는 코드입니다

2024 02 21 

linked list는 저번에 만들었던걸 그대로 가져왔습니다. append display remove 등
바뀐부분은 Node에 prev 가 추가되었고 main 함수에서 tail을 임의로 만들어서 마지막 노드를 가리키게 했습니다.

partition 함수에서는 pivot에 left의 data만 저장했습니다. Node로 할까 했는데 너무 헷갈려서...
(그래서 return 할때 pivot을 return 하지않고 high를 return 했습니다)
pivot과 low->data high->data를 비교해가며 교환할건 교환하고 아닌건 그냥 두었습니다.

quicksort_recursive 함수에서는 low high 를 받아서 pivot을 기준으로 계속 재귀적으로 함수를 수행합니다. 
