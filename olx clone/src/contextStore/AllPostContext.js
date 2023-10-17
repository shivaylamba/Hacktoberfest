import React,{createContext,useState} from 'react'


export const AllPostContext = createContext(null) ;

function ContextAllPost({children}) {
    const [allPost,setAllPost]=useState([])
    return (
        <AllPostContext.Provider value={{allPost,setAllPost}}>
            {children}
        </AllPostContext.Provider>
    )
}

export default ContextAllPost
