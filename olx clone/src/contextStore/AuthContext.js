import React,{useState,createContext} from 'react'

export const AuthContext = createContext(null)

function ContextAuth({children}) {
    const[user,setUser]=useState()
    return (
        <AuthContext.Provider value={{user,setUser}}>
            {children}
        </AuthContext.Provider>
    )
}

export default ContextAuth
