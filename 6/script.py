with open("input2.txt", "r") as f:
    content = f.read()
    lines = content.split('\n')
    cnt = len(lines)
    newls = []
    for i in range(cnt-1):
        currl = lines[i].split(" ")
        ls = []
        for curr in currl:
            if curr == "":
                ls.append("x")
            else:
                ls.append(curr)
        res= "".join(ls)
        newls.append(res)

    ops = []
    opsstr = newls[len(newls)-1]
    co = 0
    i = 0
    #print(opsstr)
    opstodo = list(filter(lambda c: c in "+*", opsstr))
    #print(opstodo)
    while  i < len(opsstr):
        while i < len(opsstr) and opsstr[i] not in ["*", '+'] :
            co+=1
            i+=1
        ops.append(co+1)
        co = 0
        i+=1
    ops = ops[1:]
    #print(ops)
    print(len(newls))

    final = []
    for s in newls:
        parts = []
        z = 0
        for n in ops:
            parts.append(s[z:z+n])
            z += n
        final.append(parts)

    final = final[:-1]
    m = len(final)
    n = len(final[0])
    
    result = 0
    opind = 0
    for j in range(n):
        temp = []
        for i in range(m):
            temp.append(final[i][j])
        newt = []
        digits = len(temp[0])
        nums = []

        for x in range(digits):
            num = 0;
            for t in temp:
                print(t)
                if t[x] == "x":
                    continue
                num = (num*10) + int(t[x])
            nums.append(num)
        tsum = 1
        if opstodo[opind] == "*":
            for e in nums:
                tsum = tsum*e
        else:
            tsum = 0
            for e in nums:
                tsum = tsum+e
        opind+=1
        result += tsum
    print(result)

                

    #for item in newls:

                    


            



