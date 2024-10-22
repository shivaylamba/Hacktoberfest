from langchain_community.llms import Ollama
from langchain_community.document_loaders import WebBaseLoader
from langchain_community.embeddings import OllamaEmbeddings
from langchain_community.vectorstores import FAISS
from langchain_core.prompts import ChatPromptTemplate
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain.chains.combine_documents import create_stuff_documents_chain
from langchain.chains import create_retrieval_chain
import wikipedia as wiki
import os

# NOTE: The following function is a RAG template written by me and wasn't copied from anywhere
def create_RAG_model(url, llm):
    # Create the LLM (Large Language Model)
    llm = Ollama(model=str(llm))
    # Define model used to embed the info
    embeddings = OllamaEmbeddings(model="nomic-embed-text")
    # Load the webpage
    loader = WebBaseLoader(str(url))
    webpage = loader.load()
    # Split the text and embed it into the vector DB
    text_splitter = RecursiveCharacterTextSplitter()
    split = text_splitter.split_documents(webpage)
    if (os.path.exists("wiki_index")):
        vector_store = FAISS.load_local("wiki_index", allow_dangerous_deserialization=True, embeddings=embeddings)
        vector_store = vector_store.from_documents(split, embeddings)
    else:
        vector_store = FAISS.from_documents(split, embeddings)
    print("[+] Finished embedding!")
    vector_store.save_local("wiki_index")

    # Prompt generation: Giving the LLM character and purpose
    prompt = ChatPromptTemplate.from_template(
    """
            Answer the following questions only based on the given context
                                                    
            <context>
            {context}
            </context>
                                                    
            Question: {input}
    """
    )
    # Linking the LLM, vector DB and the prompt
    docs_chain = create_stuff_documents_chain(llm, prompt)
    retriever = vector_store.as_retriever()
    retrieval_chain = create_retrieval_chain(retriever, docs_chain)
    return retrieval_chain

number = int(input("Do you want me to:\n 1) Learn from a single article \n 2) Learn from articles of a given topic\n :"))
if (number == 2):
    topic = input("What topic to do you want me to learn?: ")
    results = wiki.search(topic)
    for result in results:
    	wiki_url = str("https://en.wikipedia.org/wiki/"+str(result)).replace(' ','_')
    	chain = create_RAG_model(wiki_url, "dolphin-phi")
elif (number == 1):
    wiki_url = input("Give me the URL of the article: ")
    chain = create_RAG_model(wiki_url, "dolphin-phi")

print("Type 'exit' to exit")

while True:
    query = input("Ask me a question: ")
    if (query == "exit"):
        break
    else:
        output = chain.invoke({"input":query})
        print(output["answer"])
