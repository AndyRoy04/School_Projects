/* eslint-disable jsx-a11y/anchor-is-valid */
import React from 'react'
import { BsLinkedin } from 'react-icons/bs';
import {FaGithub} from 'react-icons/fa'
import {FaFacebookF} from 'react-icons/fa'
import { CgTwitter } from "react-icons/cg";

import './footer.css'
const Footer = () => {
    return (
      <div className="footer__container">
        <a href="#" className="footer__logo link_above">
          Anderson Roy
        </a>

        <ul className="permalinks">
          <li>
            <a href="#">Home</a>
          </li>
          <li>
            <a href="#about">About</a>
          </li>
          <li>
            <a href="#experience">Experience</a>
          </li>
          <li>
            <a href="#services">Services</a>
          </li>
          <li>
            <a href="#portfolio">Portfolio</a>
          </li>
          <li>
            <a href="#testimonials">Testimonials</a>
          </li>
          <li>
            <a href="#contact">Contact</a>
          </li>
        </ul>

        <div className="footer__media">
          <a href="https://www.linkedin.com/in/djeutio-anderson-roy-958b0b234/" target="_blank" rel="noreferrer">
            <BsLinkedin />
          </a>
          <a href="https://github.com/AndyRoy04/PersonalPortfolio.git" target="_blank" rel="noreferrer">
            <FaGithub />
          </a>
          <a href="https://www.facebook.com/anderson.djeutio.7" target="_blank" rel="noreferrer">
            <FaFacebookF />
          </a>
          <a href="https://twitter.com/Andersonroy1234?t=WWz8L3SWmVvuYKTkBkzsZQ&s=09" target="_blank" rel="noreferrer">
            <CgTwitter />
          </a>
        </div>

        <div className="copyRight">
            <h3>@copyright BD 2023</h3>
        </div>
      </div>
    );
}

export default Footer

