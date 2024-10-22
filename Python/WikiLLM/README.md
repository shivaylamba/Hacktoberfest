# Implementing RAG on LLMs using Wikipedia and Langchain #

## About the project ##

Hi! It's well known that Wikipedia is one of the largest knowledge bases. It has over 6,889,864 articles and is a good source of information to train LLMs on. This project simply allows LLMs to "learn" any topic or article using RAG. The LLM can learn from either a single article or all articles of a same topic.

## Tech ##

This program uses Langchain and FAISS to implement RAG, the wiki library to search for articles and Ollama to use Llama models.

## Improvements and new features ##

1) Autonomous learning using computer vision
2) A GUI

## Installation and usage ##

1) Install the dependencies

```
pip3 install langchain-community
pip3 install langchain-core
pip3 install langchain-text-splitters
pip3 install langchain
```

2) Run the program

```
python3 WikiLLM.py
```

3) Enjoy!


Happy learning!