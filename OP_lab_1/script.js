// 1
const input = document.querySelector('.input');
const resultBlock = document.querySelector('.result-block');

input.addEventListener('change', myFunc);
function myFunc() {
    let x = +this.value;
    let result = (x*x - x + 1) / Math.sqrt(x*x*x + 4);
    resultBlock.innerHTML = result;
}


// 2
const input2 = document.querySelector('.input-2');
const resultBlock_2 = document.querySelector('.result-block-2');

let copybook = 2.75;
let cover = .5;

input2.addEventListener('change', myFunc2);
function myFunc2() {
    let kits = +input2.value;
    let result2 = kits*copybook + kits*cover;
    resultBlock_2.innerHTML = result2;
}