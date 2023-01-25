
var windowWidth = 480;
var windowHeight = 480;
var boardWidth = (windowWidth>windowHeight ? windowHeight : windowWidth)*0.8;
var boardHeight = boardWidth;
var count = horse.getSize();
var cellSize = boardWidth/count;
var cell = Qt.createComponent("Cell.qml");
var cells = new Array(count*count);
var cur = 1;
var currentSHow = 0;
var currentResult = null;

function indexForCell(x, y){
    return x*count+y;
}

function createCells(board) {
    for(var i=0;i<count;i++){
        for(var j=0;j<count;j++){
            cells[indexForCell(i, j)] = cell.createObject(board, {"row":i, "col":j});
        }
    }
}

function step(cellItem){
    cellItem.number = cur++;
}

function find(){
    horse.find();
}

function load(){
    var c = cells[0];
    c.color = "black";
}
function prev(){
    horse.deductCurrentResult();
}
function next(){
    horse.appendCurrentResult();
}

function show(item, index){
    //    var s = horse.getSize();
    //    console.log(s);
    //    cells[0].number = s;
    //    var answer = horse.getResult(index);
    //    console.log(answer);
//    if(currentResult!=null){
    console.log("show> " + currentSHow);
//    if(item.row == 0 && item.col == 0){
//        currentSHow++;
//    }
        item.number = horse.getResultsValueAt(horse.getCurrentResult(), indexForCell(item.row, item.col));
//        item.number = currentResult[indexForCell(item.row, item.col)];
//    }else{
//        console.log(null);
//    }
}
