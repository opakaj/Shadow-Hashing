# Shadow-Hashing
A naive implementation of shadow hashing

Abstract: Efforts to obfuscate data as a means of data security have come a long way with cryptographic technologies since the early days of the internet. Hashing, encryption and tokenization are used to protect different kinds of data but all have some loopholes we’ll look at later. A new solution to the data breach problem is presented in this paper that assumes worst case and has the ability to maintain the integrity of data even after a data breach. Data is first hashed then sent to the shadow server through API calls. The output is hexadecimal characters of unfixed length i.e. “shadow hash” that is returned for storage and has the ability to transition to the original hash (without using a key-value mapping or key storage) with the right authentication. The result is data like passwords, primary account numbers, encryption keys etc. can stay in databases in a “shadow state” and if breached, are useless to hackers yet useful to the real owners.


## 1.	 INTRODUCTION
There isn’t a shortage of data breach examples when one carries out a simple search online. Businesses of all sizes have fallen victim to data breaches of all kinds. From the tens of millions to the hundreds of millions of records stolen, it’s a no brainer that this is a problem worth solving. And with the current security solutions in the market, from hashing to encryption to tokenization, it’s safe to say that a better approach to data security has to be undertaken or at least one that enhances or fills some of the loopholes being exploited by hackers today.
Hashing is used all over the internet to especially protect data like passwords and for message authentication. When used with a time tested algorithm without any known collusion like SHA 2 or SHA 3, one can expect fairly good security. It’s important to note that hashing has been defeated multiple times in its efforts to protect credentials thanks to the advent of cheaper and available yet powerful hardware and software that’s freely available online. 
Encryption is another time tested data security technology and when implemented well, symmetrically or asymmetrically, one can expect the confidentiality, integrity, authentication and non-repudiation it provides. But with more encryption comes more encryption keys that have to be well protected otherwise the benefits of the encryption are lost if the keys are stolen. 
Tokenization, famously used for PCI/DSS compliance provides extra security since it replaces valuable data with tokens that are useless if stolen but unfortunately keep a copy of the data being protected and thus become targets for hackers. This can somewhat be alleviated by blending tokenization with encryption but one can expect some costs on performance and again, if the keys are stolen, encryption benefits are lost, thus a possible data breach that affects not only the custodians of the data but also the data owners.
What is needed is a security system that can maintain the integrity of data even in the event of a data breach. One that is built on the basis of the worst case scenario happening i.e. data theft. This is where shadow hashing comes in. Strings of data in their hex form like encryption keys or hash digests are sent to server with the shadow hashing algorithms which have an output of arbitrary length which is then stored in databases and files. In this paper, the new solution to data theft is presented that adds another layer of security on top of hashed data. Through API calls, data can change from a hash to a shadow hashed state and back. The shadow hash is what’s stored in the database and is completely useless when stolen. The result is integrity is preserved even after a data breach and as long as authentication through the API as well as the API gateway is secure, data seamlessly changes from hash to shadow hash when needed like magic (hence the word wizard) without the use of keys like used for encryption or storage of a key-value mapping in a database like it is with tokenization.

## 2.	WHAT IS SHADOW HASHING?
Shadow hashing is the process of changing data into randomly generated characters that have no value when breached, yet possess the ability to transition back to the original data without using keys (like with encryption) or a key-value mapping in a database.
Shadow hashing primarily only acts on data in a hexadecimal form and uses a primary hashing algorithm as a source of randomness if supplied with plain text, currently SHA256. Other instantiations of shadow hashing can use other hashing algorithms for randomness or even a cryptographically pseudo random number generator.	 
A primary hashing algorithm, SHA256, is called a variable number of times, on the plain text S, giving a digest A, which is then sent to the shadow hashing algorithm SH1 in order to create the shadow hash T. This shadow hash T, can then change back to string A through API calls made to the reverse shadow hashing algorithm SH2. 
SHA256 (S) = A
SH1 (A) = T
SH2 (T) = A
The plain text may be concatenated with a salt before hashing.
It’s important to note that while hashing is not reversible and has a fixed length with a particular hashing algorithm, shadow hashing is reversible and doesn’t have a fixed length. Shadow hashing is also built on top of hashing thus, the strength of shadow hashing depends on the underlying properties of the hash function in use.
The output of the reverse shadow hashing is the previously supplied hash digest A, not the plain text (S) since the plain text was hashed and when hashed is irreversible.
If hexadecimal data K, is provided, for example as an encryption key, its sent to the shadow hashing algorithm SH1 to create its shadow hash (in this case, its shadow key) T. To reveal the actual key K from the shadow hash T, T is sent to shadow hashing algorithm SH2.
SH1 (K) = T
SH2 (T) = K
Note:
1.	In the shadow hashing algorithms, when plain text is sent, it will first be hashed with SHA256 so as to get a hexadecimal string which is then shadow hashed for storage. This shadow can be reversed to its SHA256 digest. 
2.	If a hex string is sent e.g. an encryption key or crypto currency private key, these particular strings are shadow hashed straight away since they were created with known randomness using pseudo random number generators.
3.	Shadow hashing doesn’t accept any hex string. The hex string sent for shadow hashing should be from a hashing algorithm with 32, 64 or 128 characters long or pseudo random number generators and known encryption algorithms like AES256, RSA and ECC etc. 
4.	A random hex string may be supplied for shadow hashing but it should be 32, 64 or 128 characters long.
5.	The shadow hash provided to reveal its actual hash cannot be a random hash otherwise there is no guarantee that errors won’t occur. It has to be a previously generated shadow hash for accurate results.
6.	Finally, how the algorithms are able to actually change a hash to a shadow hash and back without key-value tables of any kind as used in tokenization or key storage as used in encryption is proprietary.

## 3.	PHILOSOPHY
The design behind shadow hashing is based on one core principle.
Assume worst case: Shadow hashing’s strength is best realized when the worst case scenario occurs and that is when data from databases is breached. As long as that data stored was in a shadow state, all the hackers would have stolen is a bunch of random characters that won’t have any value to the hackers after a breach. This is something that encryption and tokenization cannot achieve as a data breach can reveal encryption keys stored in HSMs or any other vault. It’s also important to realize that shadow hashing doesn’t compete or seek to replace hashing and encryption, rather, it’s built on top of hashing and seeks to fill encryption’s loopholes like plain text key storage.
On the other hand, shadow hashing is a direct replacement to technologies like tokenization. Tokenization is the popular tech used mainly to achieve PCI/DSS compliance among businesses. It provides a random set of values that are not supposed to be reverse engineered and it also improves security and lessens the compliance burden especially on small businesses but it also comes with some limitations that we’ll get to later.
Shadow hashing also comes in different types so it’s best we iron them out right away.

## 4.	TYPES OF SHADOW HASHING
At its core, shadow hashing transforms a hash H1, into another hash (shadow hash) H2. H1 is then deleted and H2 is what’s stored in the database and can transform back to H1 without keys or key-value mappings in databases. With this in mind, one can notice the one-to-one relationship between and actual hash and a shadow hash if both are to be stored.
                                               H1                                H2
This leads us to a new way to view shadow hashing. Shadow hashing can then also be defined as a secure way of maintaining relationships between hash values and leveraging these relationships in different applications. This relationship can be done by simply having H2 as a hashed version of H1 after n hashing iterations, making n the secret. This is insecure as all hackers need to do is guess the n; number of times H1 was hashed to get H2 which is possible with current hardware and software as well as the fact that the hashing algorithms are freely available. It’s at this point when we get into the types of shadow hashing. 

1:1 Shadow hashing


1:2 Shadow hashing

																								
Note: Once we have more than one shadow hash mapping to one hash. The “hash” may not only be an actual hash from a hashing algorithm but also a hex string generated from a random number generator algorithm. If hash H is a 64 character hex;
o	It’ split into half to get two new strings S1 and S2.
o	Respective shadows for S1 and S2 are created, and the output is SH1 and SH2.
o	Now, hash H and shadows SH1 and SH2 could be identities of nodes on a network with messages broadcast to them specifically.
o	The algorithm to determine the relationship would either; pick shadow hashes SH1 and SH2, reveal the actual individual hashes through an API call to the server, concatenate the result and compare with hash H, which would be among other H’s in a database, if there’s a match, they are related or through the usual hash based way by;
o	Picking hash H, split into two, create shadow hashes through API calls and compare with a list of shadows in perhaps a database, if there’s a match, there’s a relationship and a message is sent.
o	A protocol like this would have to build on top of the TCP/IP.

1: N Shadow hashing
																																		
N: N Shadow hashing

																																																																					   With this relationship, for instance, 3 hashes are related to 10 shadows. This can be applied in blockchain environments where nodes are identified in particular block chains. A consensus algorithm can be built around this where particular nodes identified by hash values make decisions and verifications for other nodes in the network identified by their shadow hash values. These particular nodes can change during the lifetime of the blockchain change (In this case, the existing copy of the blockchain will have to be pasted to the new nodes) but the actual consensus logic doesn’t have to change. This could be optimized to allow for a higher throughput or lower latency as fewer nodes do the verification in such a way that security is not compromised. Identifying nodes through IP addresses won’t be enough as nodes change networks around the world so identifying them with a protocol/consensus algorithm that can be controlled would be necessary but that’s out of the scope of this paper.


## 5.	APPLICATION AREAS OF SADOW HASHING
Details of the application of shadow hashing will appear in subsequent papers but for now, here’s a brief outlook.

1. PCI/DSS Compliance  9030016325537  *290|
Payment security is paramount for every merchant, financial institution or any other entity that stores, processes or transmits cardholder data especially the Primary Account Number. The PCI council laid down twelve general standards under five sub-divisions that ought to be met, and are aimed at primarily protecting card holder data directly or indirectly, in transit or storage.
If you have to store PAN data, then PCI DSS requirement 3.4 requires that you render it unreadable and unrecoverable through one of the following methods:
•	One-way hashes based on strong cryptography (hash must be of the entire PAN)
•	Truncation (hashing cannot be used to replace the truncated segment of PAN)
•	Index tokens and pads (pads must be securely stored)
•	Strong cryptography with associated key-management processes and procedures [1].

All these have strengths and weaknesses especially one way hashing that renders PAN un readable but is so easy to beat given that its very implementation is also used to protect passwords and has been defeated by hackers several times with password cracking software and hardware, coupled with the fact that the hashing algorithms are readily available for anyone to tinker with. Tokenization is the one that’s been gaining ground recently and can even be used alongside encryption.
 Tokenization is commonly used to lessen the compliance burden by replacing the sensitive data in merchant servers and replacing it with tokens that are useless when breached. Tokenization has a couple of limitations but at the heart of it is the fact that a copy of the actual useful data is stored in servers as a key-value mapping which simply changes the attacker’s target from a merchant to token provider. 
Other limitations of tokenization include:
•	There are few standards and best practices leading to unsafe implementations.
•	Processing cost rises.
•	Tokens must be created for each merchant and card account acquiring new infrastructure for third parties in the transaction flow to tokenize and de-tokenize card accounts in these transactions which adds to transaction fees for third parties.
•	Payment specific tokenization locks organizations into a particular payment processor.
•	Tokens should not be replayed or reused otherwise attackers will just use this token instead of the actual data and achieve the same criminal goals. This has not yet been guaranteed not to happen [2].
With shadow hashing, primary account numbers, credit or debit, can be shadow hashed and this shadow hash is eventually what gets stored in the merchant’s database and if the worst case scenario occurs and a data breach happens, all is not lost since hackers would have stolen a bunch of useless numbers and letters. 
The core difference with tokenization is that with shadow hashing, a copy of the real data is never stored anywhere unlike tokenization and this I believe will help accelerate shadow hashing’s adoption for PCI/DSS compliance.
Furthermore, shadow hashing can be used by merchant, payment processors and other entities for unreadable yet recoverable primary account number storage and processing as required by the PCI SSC. If merchants don’t want PANs recoverable, they can simply shadow hash them as the PANs in a shadow state are more secure than normally hashed PANs in the event of a data breach. The intrinsic details of such a system will appear in subsequent papers. If merchants prefer recoverable PANs, then they will have to use known encryption algorithms, with the keys secured with shadow hashing which we get into now.

2. Encryption key management
One of encryption’s limitations is that as its use increases, so does the number of encryption keys. Keys that need unparalleled security otherwise if stolen, all the benefits of the encryption are lost. This is where key management comes in. This is done by countless companies, primarily utilizing hardware security modules (HSMs) and key management systems. HSMs are “trusted”, have outstanding and incomparable performance and are built to protect cryptographic keys [3].
An HSM is typically a server with different levels of security protection or “hardening” that prevents tampering or loss. These can be summarized as:
•	Tamper Evident: adding tamper-evident coatings or seals on screws or locks on all removable covers or doors.
•	Tamper Resistant: adding “tamper detection/response circuitry” that wipes out all sensitive data such as DEKs and KEKs.
•	Tamper Proof: complete hardening of the module with tamper evident/resistant screws and locks along with the highest sensitivity to “tamper detection/response circuitry” that wipes out all sensitive data [4].
But they do come with some limitations in the cloud like HSM choice and location, connectivity to do with increased latency if on-premise HSMs and encrypted data in the cloud, multiple cloud vendors with multiple HSMs and multiple key management tools [5]. HSMs cost (in terms of money and time) of setting up is not low, and don’t usually cater for the worst case scenario, i.e. if an HSM is breached, FIPS approved or not, keys (key encryption key or data encryption key) in the HSM are lost to hackers forever. Despite their other weaknesses like limited number of keys stored and limited key lifecycle management outside the HSM, all compared to a key manager [6], HSMs main advantage are the speed of transactions. Given that they are meant to create and protect keys, their strengths with key storage is easily eclipsed by shadow hashing given their limitations.
A key management system incorporating shadow hashing technology can be built, ensuring both physical and logical access controls. The system, if hosted in reputable cloud hosting providers, protects keys (both data encryption keys and key encryption keys) by storing them in a shadow state and are only in plain text if needed. 
Authorized persons have API access to remotely reveal the actual key from the shadow or do it directly in the application and use the key for encryption and decryption, and create its shadow again for storage. A KMS with shadow hashing technology can be implemented without HSMs especially if processing so many keys at a time is not essential. Implementing such a system with KMIP makes it even more secure.
 This process, if implemented well, happens flawlessly for the entire key lifecycle from  creation, import, export, usage, rotation and destruction and is more advanced than the current ways keys are stored today, in HSMs or not, since the keys are NEVER in plain text form.



3. Crypto currency key storage
•	Crypto currency exchanges: These exchanges typically spend millions of dollars on security for the private keys, whether in hot or cold wallets. The cold ones are also stored offline in HSMs for more security as they are where the real money is. Again, through some code changes to cater for API requests, shadow hashes of these private keys are created and are what the exchanges store in their databases. To send crypto to a particular wallet, its private key is revealed from the shadow stored in the database. If implemented well, this can be a flawless process that has keys in their actual “plain text” only when needed but by default are in a shadow state. Worst case scenario, the exchange is hacked, but hackers only have random characters with no meaningful value as the shadows of these keys have no resemblance to the actual ones. This is a level of security not available with any HSM or shadow hashing alternatives anywhere.

•	Crypto currency wallets: Crypto software wallet providers, who in this case are different from the exchanges but may be from the same parent company typically encrypt the keys and usually store them in HSMs or other highly secured servers. These wallet providers can utilize the power of shadow hashing by storing their customer’s private keys in a shadow state in their servers by default. Customers can provide legitimate credentials for access, API calls made to the shadow hashing server to reveal the actual hash from the shadow and customers proceed to spend their crypto with their legitimate public and private keys. 

4. Secure password storage and authentication
Passwords are commonly salted, hashed then stored. Authentication happens by, salting then hashing the user provided password, and a comparison is made with the stored hash. If it’s a match, then the password is correct. The mechanism has been beaten several times by hackers after launching successful offline attacks and powerful software and hardware makes the brute forcing more efficient.
With shadow hashing;
o	Passwords are salted, hashed and sent to the shadow server for shadow hashing.
o	This shadow hash is returned and is what’s stored in the database.
o	During authentication, a user enters the password, its salted, hashed and sent to the shadow server for shadow hashing.
o	The shadow hash is returned and compared with the stored shadow and if there is a match, access is granted.
o	The authentication may be implemented differently where;
o	The stored shadow of a user trying to gain access is sent to the shadow server for the actual hash to be revealed.
o	The hash is sent back and is compared with the hash of the user entered password, if there is a match, access is granted.
Consequently with shadow hashing, passwords are never stored in plain or hash form but in shadow hash form. As long as API access is properly implemented and well-fortified, a successful offline attack will only reveal shadow hashes that have no value so the worst case scenario will be covered. 
This furthermore solves not only the offline attacks on passwords but also credential stuffing attacks and will mean users simply need to get un-guessable passwords and forget about the usual password creation conditions like minimum length or large character sets.
This application of shadow hashing on passwords can also be implemented for personal identifiable information like social security numbers, telephone numbers and transmission and storage of electronic health records.

5. SHMAC-X (Shadow Hash Message Authentication Code)
Providing a way to check the integrity of information transmitted over or stored in an unreliable medium is brought about the creation of HMAC [7]. The use of HMAC comes with a secret key alongside a particular hashing function. Shadow hashing can be used to protect this key as its security is prime for the proper implementation of HMAC.
The keys, in binary form are transformed to hex, hashed and shadow hashed for storage. The reverse occurs so as to use the key for message authentication. So it’s the usual HMAC but coupled with shadow hashing to protect the key.


6. Biometric storage and authentication 

Biometrics will eventually replace passwords as a method of authentication both offline and online. This transition won’t happen easily if a robust security system is not implemented. A three layer system for biometrics is used for the shadow hashing system. 
1.	Application ( Hardware lives here)
2.	Authentication (Authentication algorithms live here)
3.	Storage (Templates live here)
A detailed explanation of these layers is beyond the scope of this paper but we’ll explain a little in the storage layer where shadow hashing operates to provide maximum security for biometric templates.
The biometric template (mathematical file containing the features of the eye or finger) is named with rogue characters i.e. the shadow hash of a random hex string e.g. from a random number generator. A random example;

Random hex string                                                   Shadow hash template file
AAE34C7F                                                               36BDD009A23F565DC10F.txt

The implementation can go as follows.
•	A database containing user names (u) and their respective random hex strings (s) exist in one table.
•	Another server with the mathematical files named as shadow hashes (sh) of the random hex strings. 
•	And the shadow server to create and reveal the shadows.
•	During authentication, a user inputs the user-name (u) and finger print (f).
•	The hex string (s) mapped to the input name (u) is sent for shadow hashing. Its shadow hash is revealed as “sh”.
•	A search is made for the file with the shadow hash “sh” as its name.
•	If found, this file is sent to a server for comparison with the mathematical representation of the input fingerprint “ f ”.
•	If there is a high enough match according to the verification algorithm, access is granted.
This implementation can definitely be done at different levels, ranging from where the files are stored i.e. centrally or in some sort of blockchain system to the verification process happening on a particular server but at the end of the day, worst case scenario happens i.e. templates are stolen, hackers simply have a bunch of random strings. The intrinsic details of biometric shadow hashing system are beyond the scope of this paper.

## 7.	The Blockchain
The problem with current blockchain operating systems lies in their low latency and throughputs i.e. they are not particularly known for their speed in comparison with centralized systems like Visa or MasterCard, as well as poor scalability and other inefficiencies.
Bitcoin’s blockchain for example, uses the proof of work algorithm for consensus but its weaknesses are a public secret in terms of the amount of energy wasted trying to verify transactions etc. and other byzantine based algorithms still don’t allow for particularly differentiating throughput as they are in the mere hundreds or at least early thousands for Ripple.



                                    Fig. 1.0 The default blockchain

To allow for particularly fast transactions, whether financial or not, at speeds that rival current centralized systems, the default blockchain concept has to be redesigned. One that is not threatened by a 51% attack, maintains reasonable scalability levels, high throughput, without compromising the security, privacy and transparency that block chains offer by default. 
While this is would be incredibly difficult to build, it would still be worth the effort. With shadow hashing, a consortium blockchain that allows for smart contract functionality and a modified consensus algorithm utilizing “n to n” shadow hashing can be created. Unlike the bitcoin blockchain, nodes will have to be identified since messages have to be routed to a particular place. Having nodes uniquely identified with shadow hashes, linked to other sort of controlling nodes identified with hash strings. These nodes can gradually change to allow for a certain targeted throughput and latency since a specific (n) number of nodes will do the verification of transactions.
So instead of having for example, 1,000,000 nodes connected peer to peer to form the blockchain, probably having each node keeping the entire history of transactions as well as  verifying these transactions (thus putting a strain on scalability), threatened by 51% attack and a consensus algorithm that kills the environment as well as other default blockchain characteristics; 
A new blockchain O.S can be created where a few thousand nodes (m) make up a small blockchain network. These small block chain networks will have a few more powerful nodes (n). The n nodes are identified by random numbers and their shadow hashes form the identities of the other m nodes in a particular small blockchain hence having some sort of relationship. These small blockchains get connected to other small blockchain networks through probably the n nodes. A new architecture for a block is also introduced for the individual blocks where different blocks, linked via their SHA256 hash, are further linked by grouping together a certain number of blocks and generating the shadow hash for such a “block-of-blocks”, making it impossible to corrupt an individual block in the network.
This design will have the following objectives (or even more):
•	To have few nodes, rather than all nodes of the entire blockchain, do the verification (an attempt to improve scalability).
•	To make a 51% attack basically impossible since shadow hashes will be needed to alter a single block/transaction.
•	To have the distributed databases of particular decentralized apps stored in small blockchains rather than the entire blockchain.
•	Have a decentralized app use the power of the entire network to run, not just the few (thousand) nodes that keep its database.
•	Ensure that as more nodes are added to the blockchain, it becomes exponentially harder to breach the network or corrupt data because shadow hashing functionality, which won’t be accessible to everyone, will be needed to hack the blockchain.
•	To have anything that connects to the internet, has a microprocessor and a certain minimum storage space, qualify as a node on the network, since not all nodes will keep the database but instead rent power to the blockchain for programs of all sizes to run. So, mobile phones, ordinary computers, super computers, satellites and even quantum computers could be part of the blockchain.
•	Have part of the consensus algorithm involved in key generation for API access to the shadow hashing servers in order to create shadow hashes for the previously mentioned block of blocks.
•	The entire block chain’s token, may or may not be recorded on every node on the blockchain.
•	Ensure that adjusting/optimizing the entire blockchain, as to which nodes keep which database, be entirely possible, in order to achieve a certain targeted throughput and latency.
•	This will definitely not be an open blockchain but rather a consortium block chain system featuring smart contract functionality, designed to address the current blockchain issues like poor scalability and low throughput.
A myriad of applications could be built on such a blockchain particularly Identity and account management software, as well as a digital identity system.    
As seen in Fig. 2.0, the black hexagonal nodes (n) are particularly more powerful than the rest. They can be in the tens, as far as their number is concerned. They also can keep the state of the entire blockchain and are identified by random numbers.
The blue nodes (m) keep the state of their particular blockchain and are identified as shadow hashes of the n IDs. The blue nodes can be in the thousands to tens of thousands or even more. 
Creating what is now called the blockchain of blockchains. This novel concept can be applied for individual blocks of data in particular nodes and networks but the intrinsic details of such a concept, is beyond the scope of this paper.
			


                                 Fig. 2.0 The new blockchain concept
					
## 8.	IoT and Robotics
The Internet of things and robots can also run on a consortium blockchain described above, or probably, any other secure blockchain. Robots and IoT devices can be controlled with smart contracts, data stored in the blockchain for security, privacy and transparency and the blockchain can be integrated with other technologies like A.I, cloud computing etc. 
Machine to machine communication is facilitated between the robots and IoT through the blockchain. Robots controlling/communicating with other robots in for example, a ware house are identified by random numbers and the controlled ones by shadow hashes of the controlling ones. These arbitrary strings can be mapped to actual names given to the robots and through integration with natural language processing and the blockchain, instructions are spoken or texted to the robots, key words are noted, triggering smart contracts and other robot controlling operations that are not necessarily smart contracts (like APIs linking to functions of the robot associated with the sensors/actuators of the robot or/and IoT device ) to cause motion or non-motion of the robot or other IoT devices with the actions or the state added to the blockchain. Other devices could wait for a particular state of the “robotic network in the ware house” stored in the blockchain in order to execute particular smart contracts, increasing trust, efficiency, longevity and transparency in IoT.
This can also be implemented in non-enterprise environments.
The intrinsic details of such a system, certainly above the O.S layer and in the decentralized application realm, are beyond the scope of this paper.

## 6.	Limitations of shadow hashing
Shadow hashing is in no way a silver bullet to the world’s data security problems and it wouldn’t be fair not to point out its limitations.
•	As of now, shadow hashing starts operating on hex data only i.e. numbers 0-9 and letters {a-f | A-F}. If any other data is supplied, its turned to hex or hashed to certain specific character lengths before its shadow hash is created.
•	Shadow hashing doesn’t protect against online attacks e.g. passwords being guessed from the forms. If hackers can successfully guess passwords online, or find a repository of plain texts and guesses them, online, one by one, they most probably will be successful. It also doesn’t protect against point of sale system attacks on card holder data.
•	Collusion within hashing algorithms compromises the system as hashing algorithms are used to create hex strings for plain text string and also with in the real shadow hashing algorithms as a source of randomness. Random number generators should also not produce two similar strings otherwise expect the same shadow string from both strings in such a scenario which could bring issues.
•	Shadow hashing heavily relies on API calls. One may not necessarily see this as a limitation since APIs can be viewed as a marvel in software engineering but the important point to note is that the API authentication and gateway will have to be flawlessly implemented in such a way that if shadow hashes are stolen from a database, it’s literally impossible to reveal their plain text from a simple API call.
•	There is a slight increase in storage space. The output of a 64 hex SHA256 hash is by default 256 characters long and can even be longer. This is an increase of more 64 bytes per record.
•	Shadow hashing is a new data security technology using known data obfuscation technologies like hashing, random number generators and encryption and many people are still skeptical about new technology especially in security. The proprietary code is how hashes actually transition to shadows and back without a key-value mapping or storage of keys as used in encryption or tokenization. Attempts to crack this code will definitely be infinite but a version of the system will be made public for shadow hashes to be created from hashes of plain text for all kinds of analysis and cracking to be levied by security professionals.


7.	Conclusion
A new approach data security has been presented in this paper i.e. shadow hashing. One with the ability to maintain the integrity of data, even after a data breach as long as API authentication is done right. Data is first hashed and the hash digest is sent to the shadow server for shadow hashing. The actual hash is deleted and its shadow hash is returned and stored in databases. During authentication, the shadow hash is sent to the shadow hash, where its actual hash is revealed and sent back for comparison with the hash of the input text e.g. a password. Worst case scenario, the database is hacked, and hackers would simply have stolen arbitrary data that they can’t make sense of.
Shadow hashing also can be done in various forms to maintain a relationship between hash values. Here, the actual hash is not deleted necessarily but a mapping of it, and its shadow are used for various applications listed in the paper. This relationship can be mapped in the legacy way by maintaining a hash of a hash but this can and has been beaten with the right hardware and software.
Shadow hashing does not guarantee that a data breach won’t occur, but it guarantees that in the unfortunate yet common event of a data breach, data integrity is intact because the data is NEVER stored in plain text but in a shadow state. If implemented well, transition of a hash to a shadow and back, happens flawlessly like magic.



References
1.	Dingman. S, “PAN storage and PCI/DSS,” 
http://www.pcicomplianceguide.org/pan-storage-and-the-pcidss, 2015.

2.	Kovacs. E, “Tokenization: Benefits and challenges of securing transaction data,” https://securityweek.com/tokenization-benefits-and-challenges-of-securing-transaction-data, 2014.

3.	Smirnof. P, “Understanding hardware security modules (HSMs),” https://cryptomathic.com/news-events/blog/understanding-hardware-security-modules-hsms, 2017.


4.	“The definitive guide to encryption key management,” https://info.townsendsecurity.com.

5.	Sheikh. I, “Hardware Security Module (HSM) Vs. Key Management Service (KMS),” https://blog.equinix.com, 2018.

6.	Czajkowski. K, “Differentiating key managers and HSMs – who let the keys out?” blog.fortinex.com/hardware-security-modules-and-encryption-key-management, 2018.
7.	H. Krawczyk, M. Bellare, R. Canetti, “HMAC: Keyed-hashing for message authentication,” ipa.go.hp/security/rfc/RFC2104EN.html, 1997.

