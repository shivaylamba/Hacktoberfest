import React, { useContext, useState } from "react";
import "./pagination.css";
import { AllPostContext } from "../../contextStore/AllPostContext";
function Pagination({ setCurrentPage }) {
  const { allPost } = useContext(AllPostContext);
  let [activeItem, setActiveItem] = useState("");
  let numberOfPages = [];
  let itemsPerPage = 8;
  for (let i = 1; i <= Math.ceil(allPost.length / itemsPerPage); i++) {
    numberOfPages.push(i);
  }
  const showNextPage = (e) => {
    let clickedPage = e.target.id;
    setCurrentPage(clickedPage);
    setActiveItem(Number(clickedPage));//Number() is used to convert string to number because here id is string and , === equals checks both side same so we want to convert it to number so we can conditionly check and active class implementation
  };
  let pagination = numberOfPages.map((pageNumber) => {
    return (
      <li
        key={pageNumber}
        id={pageNumber}
        className={activeItem === pageNumber ? "active" : ""}
        onClick={showNextPage}
      >
        {pageNumber}
      </li>
    );
  });
  return <div className="pagination">{pagination}</div>;
}

export default Pagination;
