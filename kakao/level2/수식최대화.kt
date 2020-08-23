class Solution {
       fun solution(expression: String): Long {
        var answer: Long = 0
        var orders = arrayOf("*+-","*-+","+*-","-*+","+-*","-+*")
        var switch = arrayListOf(false,false,false)
        orders.forEach{order->
            var curAnswer:Long = 0
            switch[0] = false
            expression.split(order[0]).forEach{ex->
                var curEx = 0L
                switch[1] = false
                ex.split(order[1]).forEach{ex2->
                    var curEx2 = 0L
                    switch[2] = false
                    ex2.split(order[2]).forEach{ ex3->
                        if(!switch[2]){
                            curEx2 = ex3.toLong()
                            switch[2] = true
                        }
                        else curEx2 = cal(curEx2,ex3.toLong(),order[2])
                    }
                    if(!switch[1]){
                        curEx = curEx2
                        switch[1] = true
                    }
                    else curEx = cal(curEx,curEx2,order[1])
                }
                if(!switch[0]){
                    curAnswer = curEx
                    switch[0] = true
                }
                else curAnswer = cal(curAnswer,curEx,order[0])
            }
            answer = kotlin.math.max(answer, kotlin.math.abs(curAnswer))
        }
        return answer
    }
    fun cal(n1:Long, n2:Long, op:Char):Long{
        return when(op){
            '*' -> {n1*n2}
            '+' -> {n1+n2}
            else -> {n1-n2}
        }
    }
}