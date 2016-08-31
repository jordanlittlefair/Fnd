#Foundation

##Game Engine and Tools

An *(over)*-ambitious project to create an experimental, cross-plaftorm game engine. 

___

###Features

####General

- [x] Component based *Entity System* - Extensible *Component*, *Node* and *Entity* managers to describe and store *Entity's* data. Inspired by [Unity](http://unity3d.com/).
- [x] Multi-threaded *Systems* - Fully encapsulated *Systems* to act on *Entities* via their *Nodes*, sometimes concurrently.
- [ ] Black boxed *Game Components* or *System Collections* - Graphics, Physics, Sound *Game Components* contain their own resources, and act on an *Entity's* *Node* via *Systems* which it defines (i.e. a simple Graphics component may define ModelRenderer and LightRenderer *Systems* to draw the scene to an internal buffer).
- [ ] Allow *Entities* to be written to and read from a simple file structure. This includes custom *Component* and *Node* types.

####Asset Manager

- [ ] Allow resources to be loaded into memory. These Assets are loaded into memory as a generic object, which is then passed to a *Game Component* to be instantiated (i.e. a 3D model is loaded into collections of vertices and indices, which is passed to an OpenGL or DirectX *Game Component* to be created on the GPU.
- [ ] Use [Assimp](https://github.com/assimp/assimp) to load 3D model files.

####Scripting

- [ ] Allow *Scripts* to be attached to Entities. These *scripts* are loaded and executed, and act on an *Entity's* *Nodes* in a similar way to *Systems*.

####Cross-Platform Support

- [ ] Windows Support.
- [ ] Mac Support.

####Graphics

- [ ] DirectX and OpenGL support
 - [ ] HDR deferred rendering pipeline.
 - [ ] Ambient Occlusion (SSAO).
 - [ ] Improved lighting (Physically based lighting model).
 - [ ] Anti-Aliasing (FXAA).
 - [ ] Soft Shadows.
 - [ ] Bloom.

####Physics

- [ ] [Bullet](http://bulletphysics.org/) physics library used to simulate 3D environments.

####Sound

- [ ] Find and integrate a sound library - Support ambient sounds and allow sounds to be triggered by scripts.

####VR

- [ ] Support VR ([Oculus Rift DK2](http://www.oculus.com/))