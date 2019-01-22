<?php
/*
Solve the Tower of Hanoi puzzle.
*/
class HanoiTower {
    public $disks;
    public $name;
    private $tower;
    function __construct($name, $disks = 0) {
        $this->disks = $disks;
        $this->name = $name;
        $this->tower = new \Ds\Stack();
        for ($i = $disks; $i > 0; $i--)
            $this->tower->push($i);
    }

    function Get() { return $this->tower->pop(); }

    function Put($n) { $this->tower->push($n); }

    function print() {
        echo "$this->name: ";
        while(!$this->tower->isEmpty())    
            echo $this->tower->pop(), " ";
    }
}

function solve_hanoi($n, &$from, &$through, &$to) {
    if ($n <= 0) return;
    solve_hanoi($n - 1, $from, $to, $through);
    $to->Put($from->Get());
    solve_hanoi($n - 1, $through, $from, $to);
}

$left = new HanoiTower("left", 6);
$middle = new HanoiTower("middle");
$right = new HanoiTower("right");

solve_hanoi($left->disks, $left, $middle, $right);

$left->print();
$middle->print();
$right->print();
