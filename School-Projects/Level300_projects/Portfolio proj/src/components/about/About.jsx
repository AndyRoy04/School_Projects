import React from "react";
import "./about.css";
import me from "../../assets/p6.png";
import { FaAward } from "react-icons/fa";
import { FiUsers } from "react-icons/fi";
import { VscFolderLibrary } from "react-icons/vsc";

const About = () => {
  return (
    <section id="about">
      <h5>Get to know</h5>
      <h2 className="header_two">About me</h2>
      <div className="container about__container">
        <div className="about__me">
          <div className="about__me__image">
            <img src={me} alt="Anderson " />
          </div>
        </div>
        <div className="about__me__content">
          <div className="about__cards">
            <article className="about__card">
              <FaAward className="about__icon" />
              <h5>Experience</h5>
              <small>1+ Years</small>
            </article>
            <article className="about__card">
              <FiUsers className="about__icon" />
              <h5>Clients</h5>
              <small>3 world widely</small>
            </article>
            <article className="about__card">
              <VscFolderLibrary className="about__icon" />
              <h5>Projects</h5>
              <small>2 Completed</small>
            </article>
          </div>
          <p>
            I am Djeutio Anderson a young passionate software engineer trained
            at the Faculty of Engineering and Technology(FET) of the University
            of Buea . I get my B.eng in 2025. Being on demand for experience, I
            apply to <strong>XYZ Company</strong> which accepts me and gives me
            the chance to work on real business projects in order to gain
            experience. From July 2021 to today, I learned technologies such as
            C, C++, Java, JavaScript, HTML & CSS, SQL, Python and the MERN
            stack, I am still learning and counting on the support of{" "}
            <strong>XYZ Company</strong> to increase my knowledge at end of
            being an engineer not only graduate, but also qualified in creating
            innovative solutions to complex problems. I hold a GCE Advance level
            and I can express myself in both French and English (averagely).
          </p>
          <a href="#contact" className="btn btn-primary">
            Let's talk
          </a>
        </div>
      </div>
    </section>
  );
};

export default About;
