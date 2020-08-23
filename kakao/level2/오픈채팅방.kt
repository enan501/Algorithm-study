class Solution {
    fun solution(record: Array<String>): Array<String> {
        var answer = arrayListOf<String>()
        var nickname = mutableMapOf<String,String>() // uid, nickname
        record.forEach{rec->
            var recArr = rec.split(" ")
            when(recArr[0]){
                "Enter" -> {
                    nickname[recArr[1]] = recArr[2]
                    answer.add(recArr[1]+"/님이 들어왔습니다.")
                }
                "Leave" -> {
                    answer.add(recArr[1]+"/님이 나갔습니다.")
                }
                "Change" -> { nickname[recArr[1]] = recArr[2] }
            }
        }
        for(i in 0 until answer.size){
            var uid = answer[i].split("/")[0]
            answer[i] = answer[i].replace(uid+"/",nickname[uid]!!,false)
        }
        return answer.toTypedArray()
    }
}