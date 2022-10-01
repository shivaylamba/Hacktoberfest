(ns Get-the-Caps)

;; Write a function which takes a string and returns a new string containing only the capital letters.

(defn get-the-caps [x] (reduce str (filter #(Character/isUpperCase %) x)))

(comment
  (= (get-the-caps "HeLlO, WoRlD!") "HLOWRD")
  (= (get-the-caps "$#A(*&987Zf") "AZ")
  )