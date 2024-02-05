# project
c++ study

  여쭤볼 부분:
굳이 class를 안 써도 되는 경우 class를 안 써도 되는지 아니면 되도록이면 그냥 써주는게 좋은지

  merge_two_area 함수:

fidx: left area 의 첫번째 idx
ridx: right area 의 첫번째 idx
sidx: temp vector의 idx

한쪽 area가 다 정렬될때까지 temp vector 에 저장
반복문이 끝나면 남은쪽 area의 정보를 한번에 temp vector 로 넣어주기 
temp vector에 있던 정보를 다시 원래 arr에 넣기

  mergesort 함수:

mid= left와 right의 가운데 idx 
mid를 기준으로 양쪽 area를 각각 재귀함수로 호출, merge_two_area 해주기

  main  함수:

vector v를 만들고 요소 개수 (N) 와 해당 요소개수만큼 숫자(temp)를 입력 받기 -> v.push_back
vector temp 를 초기화시켜주기 -> temp.resize(N) 
mergesort 호출

