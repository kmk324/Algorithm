def solution(cacheSize, cities):
    answer = 0
    cacheTable=[]
    if (cacheSize == 0):
        return  5 * len(cities)
    else :
        while(len(cities)):
            if cities[0].lower() in cacheTable:
                cacheTable.remove(cities[0].lower())
                cacheTable.append(cities[0].lower())
                cities.pop(0)
                answer+=1
            else:
                if(len(cacheTable)==cacheSize):
                    cacheTable.pop(0)
                cacheTable.append(cities[0].lower())
                cities.pop(0)
                answer+=5
    return answer
