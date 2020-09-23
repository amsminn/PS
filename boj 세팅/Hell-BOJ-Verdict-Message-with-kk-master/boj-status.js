let arr = document.getElementsByClassName("result");
let stat = document.getElementById('status-table');

const RED = "<span class=\"result-wa \">";
const BLUE = "<span class=\"result-ce \">";
const GREEN = "<span class=\"result-ac \">";
const END = "</span>";
const conv = {
    "맞았습니다!!": "올ㅋ 맞음",
    "틀렸습니다": `${END}${RED}응 아니야`,
    "런타임 에러": "인덱스 제발",
    "시간 초과": `${END}${RED}니 코드 느려! 니 코드 느려!`,
    "컴파일 에러": `${END}${RED}문법 공부 좀...`,
    "메모리 초과": `${END}${RED}메모리 펑`,
    "출력 초과": "출력 초과"
};


let t = 1, tmp = "", id;

for(let i in arr){
    let now = arr[i].innerHTML;
    let str = arr[i].innerText;
    
    if(conv[str] == undefined) continue;

    id = stat.rows[i].cells[0].textContent;

    now = now.replace(str, conv[str]);

    tmp = id;
    arr[i].innerHTML = now;
}
