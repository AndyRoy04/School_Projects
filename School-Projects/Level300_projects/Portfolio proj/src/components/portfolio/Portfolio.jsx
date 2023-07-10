import React, { useEffect, useState } from "react";
import "./portfolio.css";
import axios from "axios";

export const Portfolio = () => {
  const [data, setData] = useState([]);
  useEffect (()=>{
    axios.get("http://localhost:8000/api/portfolio")
    .then(resp => {
      const formattedData = resp.data.data.map(item =>({
        id:item._id,
        image: item.image,
        title: item.title,
        github: item.github,
        demo: item.demo
      }));
      setData(formattedData)
    })
    .catch(error =>{
      console.log('Error fetching Portfolio Data', error);
    })
  },[])
  return (
    <section id="portfolio">
      <h5>My recent work</h5>
      <h2 className="header_two">Portfolio</h2>
      <div className="container portfolio__container">
      {
        data.map(({id, image, title, github, demo}) => (
            <article key={id} className="portfolio__item">
              <div className="portfolio__item__image">
                <img src={image} alt=" one" className="portImage" />
              </div>
              <h3> {title} </h3>
              <div className="portfolio__item__cta">
                <a
                  href={github}
                  className="btn"
                  target="_blank"
                  rel="noreferrer"
                >
                  Github
                </a>
                <a
                  href={demo}
                  className="btn btn-primary"
                  target="blank"
                  rel="noreferrer"
                >
                  Live Demo
                </a>
              </div>
            </article>
          ))
      }
      </div>
    </section>
  );
};
export default Portfolio;
