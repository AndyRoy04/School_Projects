import React from "react";
import "./experience.css";
import {FiCheckCircle} from 'react-icons/fi'

export const Experience = () => {
  return (
    <section id="experience">
      <h5>What skills i have</h5>
      <h2 className="header_two">My Experience</h2>

      <div className="container experience__container">
        <div className="frontend_experience">  
          <h3>Frontend Development</h3>
          <div className="experience_content">
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>HTML</h4>
              <small className="text-light">Experienced</small></div>
            </article>
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>CSS</h4>
              <small className="text-light">Intermediate</small></div>
            </article>
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>JavaScript</h4>
              <small className="text-light">Basic</small></div>
            </article>
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>React</h4>
              <small className="text-light">Unexperienced</small></div>
            </article>
          </div>
        </div>

        <div className="backend_experience">  
          <h3>Backend Development</h3>
          <div className="experience_content">
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>MySQL</h4>
              <small className="text-light">Experienced</small></div>
            </article>
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>Python</h4>
              <small className="text-light">Basic</small></div>
            </article>
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>Java</h4>
              <small className="text-light">Basic</small></div>
            </article>
            <article className="experience_details">
              <FiCheckCircle className='experience__details-icons'/><div>
              <h4>PHP</h4>
              <small className="text-light">Unexperienced</small></div>
            </article>
          </div>
        </div> 
       
        <div className="frontend_experience">  
          <h3>Other Experiences</h3>
          <div className="experience_content">
            <article className="experience_details">
            <FiCheckCircle className='experience__details-icons'/><div>
            <h4>UI/UX</h4>
            <small className="text-light">Intermediate</small></div>
          </article>
          <article className="experience_details">
            <FiCheckCircle className='experience__details-icons'/><div>
            <h4>Agile Methodology</h4>
            <small className="text-light">Intermediate</small></div>
          </article>
        </div>
      </div>
      </div>
    </section>
  );
};
export default Experience;

