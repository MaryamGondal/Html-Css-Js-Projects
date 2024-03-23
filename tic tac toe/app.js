
let boxes=document.querySelectorAll(".box");

let resetBtn=document.querySelector("#reset");

let newGameBtn= document.querySelector("#newbtn");
let msgContainer = document.querySelector(".msg-container");
let msg=document.querySelector("#msg");

let turnO = true; //player O
let count=0;

const winPatterns = [
    [0,1,2],
    [0,3,6],
    [0,4,8],
    [1,4,7],
    [2,5,8],
    [2,4,6],
    [3,4,5],
    [6,7,8],
    
];





boxes.forEach( (box) => {
    box.addEventListener("click" , () =>{
        if(turnO==true){
            box.classList.add("o");
            box.innerText= "O";
            
            turnO= false;
        }
        else{
            box.classList.add("x");
            box.innerText= "X";
            turnO = true;
        }
        box.disabled=true;
        count++;

        let isWinner= checkWinner();
        if(count === 9 && !isWinner){
            drawMatch();
        }

      //  checkWinner();
    });
});


const Reset = () => {
    turnO = true;
    count=0;
    enable();
    msgContainer.classList.add("hide");
};


const disable = () =>{
    for(let box of boxes){
        box.disabled= true;
    }
}

const enable = () =>{
    for(let box of boxes){
        box.disabled= false;
        box.innerText = "";
    }
}
const showWinner = (winner) => {
    msg.innerText= `Congratulations, Winner is ${winner}`;
    msgContainer.classList.remove("hide");
    disable();
}


const checkWinner = () => {
    for (let pattern of winPatterns){
        
        let pos1Val =  boxes[ pattern[0] ].innerText;
        let pos2Val =  boxes[ pattern[1] ].innerText; 
        let pos3Val =  boxes[ pattern[2] ] .innerText;

        if(pos1Val != "" && pos2Val != "" && pos3Val != ""){
            if(pos1Val === pos2Val && pos2Val === pos3Val){
                
                showWinner(pos1Val);
            }
        }    
    }
};

const drawMatch = () => {
    
    msg.innerText="Match was a draw!";
    msgContainer.classList.remove("hide");
    disable();
}

newGameBtn.addEventListener("click" , Reset);
resetBtn.addEventListener("click" , Reset);
