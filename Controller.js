
var windowWidth = 480;
var windowHeight = 480;
var boardWidth = (windowWidth>windowHeight ? windowHeight : windowWidth)*0.9;
var boardHeight = boardWidth;
var count = 8;
var cellSize = boardWidth/count;
var cell = Qt.createComponent("Cell.qml");
var cells = new Array(count*count);
var cur = 1;

function index(x, y){
    return x*count+y;
}

function createCells(board) {
    for(var i=0;i<count;i++){
        for(var j=0;j<count;j++){
            cells[index(i, j)] = cell.createObject(board, {"row":i, "col":j});
        }
    }
}

function step(cellItem){
    cellItem.number = cur++;
}
