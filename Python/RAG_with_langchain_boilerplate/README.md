# Rag boilerplate in Python using LangChain #

### About RAG ###
Hi there! This is a RAG(Retrieval Augmented Generation) boilerplate/template in Python. RAG is an amazing technology that links input sources(PDFs in this case) to LLMs(Large Language Models). Then, the LLMs gain the ability to answer questions that  they initially didn't know about.

### How RAG works ###
RAG works by splitting the input file(s) into semantically related chunks and embeds these chunks into a vector database. A vector database stores data in a mathematical representation to enable speedy access(of course, machines are more fluent in math). When a prompt or query is given by the user, it gets embedded into the vector DB too. Then, the data stored alongside the query are returned(the data stored alongside the query are the most related because the data is embedded semantically).

### Installation and use ###
1) Install dependencies

```
pip3 install langchain-community
pip3 install langchain-core
pip3 install langchain-text-splitters
pip3 install langchain
```

(excuse me if you find any missing dependencies)

2) Use the template

Refer to the commented code at the end of the ```RAG_boilerplate.py``` file and modify it to suit your needs (remember to uncomment the code block).

3) Download a PDF input file and execute

Download a PDF to implement RAG on (also, specify it in the code) and execute it using ```python3 RAG_boilerplate.py```

4) Happy learning!



