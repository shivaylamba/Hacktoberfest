from langchain_community.llms import Ollama
from langchain_community.document_loaders import PyPDFLoader
from langchain_community.embeddings import OllamaEmbeddings
from langchain_community.vectorstores import FAISS
from langchain_core.prompts import ChatPromptTemplate
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain.chains.combine_documents import create_stuff_documents_chain
from langchain.chains import create_retrieval_chain

def create_RAG_model(input_file, llm):
    # Create the LLM (Large Language Model)
    llm = Ollama(model="dolphin-phi")
    # Define model used to embed the info
    embeddings = OllamaEmbeddings(model="nomic-embed-text")
    # Load the PDF
    loader = PyPDFLoader(input_file)
    doc = loader.load()
    # Split the text and embed it into the vector DB
    text_splitter = RecursiveCharacterTextSplitter()
    split = text_splitter.split_documents(doc)
    vector_store = FAISS.from_documents(split, embeddings)


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

# Using the retrieval chain
# Example:

'''
chain = create_RAG_model("your_file_here.pdf", "mistral")
output = chain.invoke({"input":"What is the purpose of RAG?"})
print(output["answer"])
'''

