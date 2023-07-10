import React from 'react'
import './services.css'
import {BiCheckboxSquare} from 'react-icons/bi'
import {BiCheckbox} from 'react-icons/bi'


export const Services = () => {
  return (
    <section id="services">
      <h5>What i offer</h5>
      <h2 className="header_two">Services</h2>

      <div className="container services__container">
        <article className="service">
          <div className="service__head">
            <h3>UI/UX Design</h3>
          </div>

          <ul className='service__list'>
            <li>
              <BiCheckbox className='service__list-icon'/>
              <p>Provide Quality visual and software designs</p>
            </li>
            <li>
              <BiCheckboxSquare className='service__list-icon'/>
              <p>Craete posts for Social medias</p>
            </li>
            <li>
              <BiCheckbox className='service__list-icon'/>
              <p>Easy collaboration with other departments</p>
            </li>
            <li>
              <BiCheckboxSquare className='service__list-icon'/>
              <p>Can design Wireframes and userflow diagrams</p>
            </li>
            <li>
              <BiCheckbox className='service__list-icon'/>
              <p> .  . .  .  .  .  .</p>
            </li>
          </ul>
        </article>

        <article className="service">
          <div className="service__head">
            <h3>Web Development</h3>
          </div>

          <ul className='service__list'>
            <li>
              <BiCheckbox className='service__list-icon'/>
              <p>Can develope and deploy a website and a web app</p>
            </li>
            <li>
              <BiCheckboxSquare className='service__list-icon'/>
              <p>Designing web layout</p>
            </li>
            <li>
              <BiCheckbox className='service__list-icon'/>
              <p>Produce responsive design for different devices</p>
            </li>
            <li>
              <BiCheckboxSquare className='service__list-icon'/>
              <p>Make use of Version control</p>
            </li>
            <li>
              <BiCheckbox className='service__list-icon'/>
              <p> .  . .  .  .  .  .</p>
            </li>
          </ul>
        </article>
      </div>
    </section>
  );
}
export default Services;

