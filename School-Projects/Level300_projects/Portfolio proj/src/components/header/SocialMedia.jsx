import React from "react";
import { BsLinkedin } from "react-icons/bs";
import { FaGithub } from "react-icons/fa";
import { FaFacebookF } from "react-icons/fa";
import { CgTwitter } from "react-icons/cg";

const HeaderSocial = () => {
  return (
    <div className="header__social">
      <a href="https://www.linkedin.com/in/djeutio-anderson-roy-958b0b234/" target="blank">
        <BsLinkedin />
      </a>
      <a href="https://github.com/AndyRoy04/PersonalPortfolio.git" target="blank">
        <FaGithub />
      </a>
      <a href="https://www.facebook.com/anderson.djeutio.7" target="blank">
        <FaFacebookF />
      </a>
      <a href="https://twitter.com/Andersonroy1234?t=WWz8L3SWmVvuYKTkBkzsZQ&s=09" target="blank">
        <CgTwitter />
      </a>
    </div>
  );
};
export default HeaderSocial;
