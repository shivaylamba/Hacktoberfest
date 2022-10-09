<?php

/**

 * User: Mario

 * Description: This is the simplest implementation of a stopwatch which can be used to test performance of your code.

 */



class Stopwatch

{

    private $stopwatches = [];



    private $results = [];



    private static $instance;

    

    private function __construct() {}

    

    public function __destruct()

    {

        print_r($this->getResults());

    }

    

    public static function getInstance(): Stopwatch

    {

        if (is_null(static::$instance)) {

            static::$instance = new static();

        }

        

        return static::$instance;

    }



    public function start(string $name)

    {

        if (isset($this->stopwatches[$name])) {

            throw new Exception('"' . $name . '" already exist');

        }



        $this->stopwatches[$name] = microtime(true);

    }



    public function stop(string $name)

    {

        if (!isset($this->stopwatches[$name])) {

            throw new Exception('"' . $name . '" doesn\'t exist');

        }



        $this->results[$name] = microtime(true) - $this->stopwatches[$name];

    }



    public function getResults(): array

    {

        return $this->results;

    }



    public function reset()

    {

        $this->results = [];

        $this->stopwatches = [];

    }

}



class Program

{

    public function main()

    {

        $stopwatch = Stopwatch::getInstance();

        

        $stopwatch->start('testMain');

        

        $stopwatch->start('testNormalMethod');

        $this->normalMethod();

        $stopwatch->stop('testNormalMethod');

        

        $stopwatch->start('testSlowMethod');

        $this->slowMethod();

        $stopwatch->stop('testSlowMethod');

        

        $stopwatch->stop('testMain');

    }

    

    private function normalMethod(): int

    {

        return 8032019;

    }

    

    private function slowMethod()

    {

        sleep(1);

    }

}



$p = new Program;

$p->main();
