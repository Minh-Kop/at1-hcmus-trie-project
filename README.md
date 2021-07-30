# I. Team Information

## Group Members

- Lê Trần Trung Hiếu [20127158] [@trunghieumickey](https://github.com/trunghieumickey)
- Nguyễn Lê Sơn [20127309] [@quanlinhson](https://github.com/quanlinhson)
- Lê Phan Duy Tùng [20127661] [@TungAlter](https://github.com/TungAlter)
- Trần Nguyễn Minh Khôi [20127538] [@Minh-Kop](https://github.com/Minh-Kop)

*github accounts included to tracking commits on github

## Class Info
- Class ID: **20CLC01**.
- Subject: 	Data Structure & Algorithms.
- Instructors: Bùi Huy Thông, Nguyễn Ngọc Thảo.
- Project subject: Advanced Tree 1 - Trie

## Group ID
- Group ID : **E**
- Topic ID : **16**

# II. Introduction
## Build Status
[![C/C++ CI](https://github.com/trunghieumickey/at1-hcmus-trie-project/actions/workflows/build.yml/badge.svg)](https://github.com/trunghieumickey/at1-hcmus-trie-project/actions/workflows/build.yml) https://github.com/trunghieumickey/at1-hcmus-trie-project
## Building Project
There are many ways this project can be built.

GNU C++
```bash
g++ **.cpp -o trie
```

Clang++
```bash
Clang++ **.cpp -o trie
```

Visual C++
```bash
cl -Fe: trie.exe **.cpp 
```

## Program Usage
### Demo

# III. Project Report
Trie is a special data structure of the tree.Every node of Trie consists of multiple branches. Each branch represents a possible character of keys and we using a trie node field isEnd is used to distinguish the node as end of word node.
Trie is a special data structure of the tree.Every node of Trie consists of multiple branches. Each branch represents a possible character of keys and we using a trie node field isEnd is used to distinguish the node as end of word node.
## Insertion
Initially, our trie has a root whose branches are empty and its boolean is false
### Step 1 : Insert "abc"

