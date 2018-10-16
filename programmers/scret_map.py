# 카카오 예선1차 비밀지도 문제

# 두 arr를 or연산 하여 계산한 값을 2진수로 변환 + zfill(n) 하여 새로운 arr에 저장해주고
# 그 arr를 쭉 돌면서 # or ' ' 매칭하여 추가하기.
def solution(n, arr1, arr2):
    answer = []
    or_arr=[]
    for i in range(n):
        or_arr.append( format((arr1[i] | arr2[i]) , 'b').zfill(n) )
    for i in range(len(or_arr)):
        row=""
        for num in or_arr[i]:
            if num == '1' :
                row += '#'
            else:
                row += ' '
        answer.append(row)
    return answer
