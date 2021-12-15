# Random
![GitHub release](https://img.shields.io/github/v/release/Capella87/Random) 
![GitHub](https://img.shields.io/github/license/Capella87/Random)
![Actions](https://github.com/Capella87/Random/actions/workflows/msbuild.yml/badge.svg?branch=master)

## Introduction
Random is a simple random number generator written in C for Windows.<br>
This project is for studying C programming.

## Prerequisite for build
* Windows 10 or later
* Visual Studio 2022 or later (Community edition is enough)
* Windows SDK 10.0.19041 (Windows 10 2004) or later
* C17 or later
* C++11 or later

That's done!

## Platforms
Currently only support Windows 10 and 11 (because it has same kernel version). I configured SupportedOS element which only included Windows 10 on rand.manifest and it's merged into the original embedded manifest every compile. But it should be fine running on older Windows versions up to Windows Vista if you remove rand.manifest, change project configuration regarding manifest and rebuild.

## Commands
```
> rand <command> [<options>]
```
* gen      : Generate random numbers.


## Features
* Generate random number with range what ever you want
* Offer argument options for quick results.

## What's next?
* Algorithm option
* Verbose option
* Statistics feature
* Mersenne Algorithm support
* WELL algorithm
* Dice
* Export to text files

## Disclaimer
This software is under construction. Additional features will be implemented in future.

## Feedback
If you have any feature suggestion or discover any error or bug, Please use issue tracker to let me know.

---
Last Updated on Dec 15, 2021
